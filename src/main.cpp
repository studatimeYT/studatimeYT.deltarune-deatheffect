#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <sstream>
#include <iomanip>

using namespace geode::prelude;

class $modify(PlayLayer) {
    void destroyPlayer(PlayerObject* player, GameObject* object) {
        PlayLayer::destroyPlayer(player, object);
        
        // 1. Play your custom death sound effect
        FMODAudioEngine::sharedEngine()->playEffect("explode_11.ogg"_spr);

        // 2. Create an animation sequence using your 17 sprite frames
        auto animation = CCAnimation::create();
        for (int i = 1; i <= 17; i++) {
            // Safe, standard C++ way to format "boom-explosion_01.png", "boom-explosion_02.png", etc.
            std::stringstream ss;
            ss << "boom-explosion_" << std::setw(2) << std::setfill('0') << i << ".png";
            std::string frameName = ss.str();

            auto frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frameName.c_str());
            if (frame) {
                animation->addSpriteFrame(frame);
            }
        }
        animation->setDelayPerUnit(0.05f); // Controls the speed of the explosion

        // 3. Create the sprite, apply the animation, and add it to the screen
        auto explosionSprite = CCSprite::createWithSpriteFrameName("boom-explosion_01.png");
        if (explosionSprite) {
            explosionSprite->setPosition(player->getPosition());
            explosionSprite->runAction(CCAnimate::create(animation));
            this->addChild(explosionSprite, 100);
        }
    }
};
