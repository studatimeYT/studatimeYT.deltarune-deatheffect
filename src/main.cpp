#include <geode/geode.hpp>

using namespace geode::prelude;

void playdeltaruneexplosion(ccnode* parent, ccpoint position) {
    auto spriteframecache = ccspriteframecache::sharedspriteframecache();
    
    auto explosionsprite = ccsprite::createwithspriteframename("boom-explosion_01.png");
    if (!explosionsprite) return;
    
    explosionsprite->setposition(position);
    parent->addchild(explosionsprite);

    auto frames = ccarray::create();
    for (int i = 1; i <= 17; i++) {
        std::string framename = fmt::format("boom-explosion_{:02d}.png", i);
        auto frame = spriteframecache->spriteframebyname(framename.c_str());
        if (frame) {
            frames->addobject(frame);
        }
    }

    auto animation = ccanimation::createwithspriteframes(frames, 0.04f);
    auto animateaction = ccanimate::create(animation);
    auto removeaction = ccremoveself::create();
    auto sequence = ccsequence::create(animateaction, removeaction, nullptr);
    
    explosionsprite->runaction(sequence);
}

$execute {
    log::info("deltarune death effect setup complete!");
}
