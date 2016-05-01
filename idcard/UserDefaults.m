//
//  UserDefaults.m
//  idcard
//
//  Created by hxg on 16-4-10.
//  Copyright (c) 2016年 林英伟. All rights reserved.
//

#import "UserDefaults.h"

static NSString* USING_VERIFY_DEFAULTS_KEY = @"usingVerify";

@implementation UserDefaults

+ (void) initialize {
	[[NSUserDefaults standardUserDefaults]
     registerDefaults: @{
                         USING_VERIFY_DEFAULTS_KEY : [NSNumber numberWithBool:YES],
                         }];
}

+ (BOOL) usingVerify {
    return [[NSUserDefaults standardUserDefaults] boolForKey:USING_VERIFY_DEFAULTS_KEY];
}

+ (void) setUsingVerify:(BOOL)x {
    [[NSUserDefaults standardUserDefaults] setBool:x forKey:USING_VERIFY_DEFAULTS_KEY];
}

@end