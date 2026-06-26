#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
    void destroyPlayer(PlayerObject* player, GameObject* obstacle) {
        auto gm = GameManager::sharedState();
        bool usingEffect19 = (gm->getPlayerDeathEffect() == 18);

        if (usingEffect19) {
            FMODAudioEngine::sharedEngine()->playEffect("explode_11.ogg"_fsr);
            
            auto playerPos = player->getPosition();
            
            auto explosionSprite = CCSprite::create("boom-explosion_01.png");
            if (explosionSprite) {
                explosionSprite->setPosition(playerPos);
                explosionSprite->setScale(1.5f);
                
                auto animation = CCAnimation::create();
                for (int i = 1; i <= 17; i++) {
                    std::string frameName = fmt::format("boom-explosion_{:02d}.png", i);
                    animation->addSpriteFrameWithFile(frameName.c_str());
                }
                
                animation->setDelayPerUnit(0.04f); 
                animation->setRestoreOriginalFrame(false);
                
                auto animateAction = CCAnimate::create(animation);
                auto removeAction = CCRemoveSelf::create();
                auto sequence = CCSequence::create(animateAction, removeAction, nullptr);
                
                explosionSprite->runAction(sequence);
                this->addChild(explosionSprite, 100); 
            }
            
            PlayLayer::destroyPlayer(player, obstacle);
        } else {
            PlayLayer::destroyPlayer(player, obstacle);
        }
    }
};
