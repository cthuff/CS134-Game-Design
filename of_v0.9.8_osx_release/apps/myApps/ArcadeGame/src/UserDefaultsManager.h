//
//  UserDefaultsManager.h
//  ArcadeGame
//
//  Created by Craig on 4/10/18.
//
//

#pragma once
#include <CoreFoundation/CoreFoundation.h>

#define UD_B_LaunchAtStartup @"UD_B_LaunchAtStartup"

#define UD_WINDOW_X @"UD_WINDOW_X"
#define UD_WINDOW_Y @"UD_WINDOW_Y"
#define UD_WINDOW_W @"UD_WINDOW_W"
#define UD_WINDOW_H @"UD_WINDOW_H"

#ifdef OF_DEBUG
ofSetDataPathRoot("../Resources/");
#endif

class UserDefaultsManager {
public:
    
    static NSDictionary * defaultValues() {
        static NSDictionary *dict = nil;
        if (!dict) {
            dict = [[NSDictionary alloc] initWithObjectsAndKeys:
                    [NSNumber numberWithBool:YES], UD_B_LaunchAtStartup,
                    [NSNumber numberWithInteger:10], UD_WINDOW_X,
                    [NSNumber numberWithInteger:10], UD_WINDOW_Y,
                    [NSNumber numberWithInteger:1400], UD_WINDOW_W,
                    [NSNumber numberWithInteger:900], UD_WINDOW_H,
                    nil];
        }
        return dict;
    }
    
    
    static void registerDefaults() {
        [[NSUserDefaults standardUserDefaults] registerDefaults:defaultValues()];
        [[NSUserDefaultsController sharedUserDefaultsController] setInitialValues:defaultValues()];
    }
    
    // save method //
    static bool sync() {
        return [[NSUserDefaults standardUserDefaults] synchronize];
    }
    
    static bool getBool( NSString* aKey ) {
        return [[NSUserDefaults standardUserDefaults] boolForKey:aKey];
    }
    
    static void setBool( NSString* aKey, BOOL aBool ) {
        [[NSUserDefaults standardUserDefaults] setBool:aBool forKey:aKey];
    }
    
    static int getInt( NSString* aKey ) {
        return [[NSUserDefaults standardUserDefaults] integerForKey:aKey];
    }
    
    static void setInt( NSString* aKey, int aInt ) {
        [[NSUserDefaults standardUserDefaults] setInteger:aInt forKey:aKey];
    }
    
    
};

