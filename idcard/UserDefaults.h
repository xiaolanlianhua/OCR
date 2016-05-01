//
//  UserDefaults.h
//  idcard
//
//  Created by hxg on 16-4-10.
//  Copyright (c) 2016年 林英伟. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UserDefaults : NSObject

+ (BOOL) usingVerify;
+ (void) setUsingVerify:(BOOL)x;

@end
