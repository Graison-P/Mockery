#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <cstdlib> // For rand(). Why do I need to include something for a simple function??

using namespace geode::prelude;

class $modify(PlayerObject) {
    void playerDestroyed(bool p0) {
        // call player death
        PlayerObject::playerDestroyed(p0);

        // pick random num 1-5 for sound
        int soundID = std::rand() % 5 + 1;
        
        // construct file name
        std::string soundFile = std::to_string(soundID) + ".ogg"_spr;

        // play file into engine
        FMODAudioEngine::sharedEngine()->playEffect(soundFile);
    }
};
