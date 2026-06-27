#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
    void destroyPlayer(PlayerObject* player, bool p1) {
        auto gm = GameManager::get();
        // Checks if the player is using death effect 19 (index 18 internally)
        bool usingEffect19 = (gm->m_playerDeathEffect == 18);

        if (usingEffect19) {
            // Play custom audio asset safely from your files block
            FMODAudioEngine::sharedEngine()->playEffect("explode_11.ogg"_spr);
            
            auto playerPos = player->getPosition();
            
            // Load the first frame out of the compiled sprite sheet
            auto explosionSprite = CCSprite::createWithSpriteFrameName("boom-explosion_01.png");
            if (explosionSprite) {
                explosionSprite->setPosition(playerPos);
                explosionSprite->setScale(1.5f);
                
                auto animation = CCAnimation::create();
                auto cache = CCSpriteFrameCache::sharedSpriteFrameCache();

                // Loop to build the 17-frame animation from the cache
                for (int i = 1; i <= 17; i++) {
                    std::string frameName = fmt::format("boom-explosion_{:02d}.png", i);
                    auto frame = cache->spriteFrameByName(frameName.c_str());
                    if (frame) {
                        animation->addSpriteFrame(frame);
                    }
                }
                
                animation->setDelayPerUnit(0.04f); 
                animation->setRestoreOriginalFrame(false);
                
                auto animateAction = CCAnimate::create(animation);
                auto removeAction = CCRemoveSelf::create();
                auto sequence = CCSequence::create(animateAction, removeAction, nullptr);
                
                explosionSprite->runAction(sequence);
                
                // Add sprite to the active gameplay object layer
                if (this->m_objectLayer) {
                    this->m_objectLayer->addChild(explosionSprite, 100); 
                } else {
                    this->addChild(explosionSprite, 100);
                }
            }
        }

        // Run standard base game logic so death registration finishes
        PlayLayer::destroyPlayer(player, p1);
    }
};
