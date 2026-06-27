#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
    void destroyPlayer(PlayerObject* player, bool p1) {
        auto gm = GameManager::get();
        // Checks if the player is using death effect 19 (index 18 internally)
        bool usingEffect19 = (gm->m_playerDeathEffect == 18);

        if (usingEffect19) {
            // 1. Fixed the literal tag to use the correct _spr marker
            FMODAudioEngine::sharedEngine()->playEffect("explode_11.ogg"_spr);
            
            auto playerPos = player->getPosition();
            
            // 2. Load from the compiled sprite sheet sheet instead of searching raw files
            auto explosionSprite = CCSprite::createWithSpriteFrameName("boom-explosion_01.png");
            if (explosionSprite) {
                explosionSprite->setPosition(playerPos);
                explosionSprite->setScale(1.5f);
                
                auto animation = CCAnimation::create();
                auto cache = CCSpriteFrameCache::sharedSpriteFrameCache();

                // 3. Loop through your 17 frames safely using the sprite cache framework
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
                
                // Add to the object layer so it renders behind UI elements properly
                if (this->m_objectLayer) {
                    this->m_objectLayer->addChild(explosionSprite, 100); 
                } else {
                    this->addChild(explosionSprite, 100);
                }
            }
        }

        // Always call the original function so the player actually dies!
        PlayLayer::destroyPlayer(player, p1);
    }
};
