#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
    void destroyPlayer(PlayerObject* player, GameObject* object) {
        // Run the original game code first
        PlayLayer::destroyPlayer(player, object);
        
        // 1. Play your custom death sound effect safely using Geode's audio manager
        log::info("Player died, attempting to play sound and animation.");
        geode::utils::audio::playEffect("explode_11.ogg"_spr);

        // 2. Create an animation sequence using your 17 sprite frames
        auto animation = CCAnimation::create();
        for (int i = 1; i <= 17; i++) {
            auto frameName = std::string("boom-explosion_") + (i < 10 ? "0" : "") + std::to_string(i) + ".png";
            auto frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frameName.c_str());
            if (frame) {
                animation->addSpriteFrame(frame);
            }
        }
        animation->setDelayPerUnit(0.05f);

        // 3. Create the sprite, grab coordinates, and add it to the layer safely
        if (player) {
            auto explosionSprite = CCSprite::createWithSpriteFrameName("boom-explosion_01.png");
            if (explosionSprite) {
                // Get absolute coordinates to prevent type crashes
                float posX = player->getPositionX();
                float posY = player->getPositionY();
                
                explosionSprite->setPosition(ccp(posX, posY));
                explosionSprite->runAction(CCAnimate::create(animation));
                
                this->addChild(explosionSprite, 100);
            }
        }
    }
};
