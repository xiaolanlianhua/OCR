//
//  ViewController.m
//  idcard
//
//  Created by hxg on 16-4-10.
//  Copyright (c) 2016年 林英伟. All rights reserved.
//

#import "ViewController.h"
#import "IDCardViewController.h"
#import "UserDefaults.h"

@interface ViewController ()

@end

@implementation ViewController


- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)viewWillDisappear:(BOOL)animated
{
    [UserDefaults setUsingVerify:false];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

//判断是ipad还是iphone
-(bool)isDevice:(NSString*)devName
{
    NSString* deviceType = [UIDevice currentDevice].model;
    NSLog(@"deviceType = %@", deviceType);
    
    NSRange range = [deviceType rangeOfString:devName];
    return range.location != NSNotFound;
}

-(IBAction) btnRecognitPressed:(id)sender
{
    
    IDCardViewController *controller = [[IDCardViewController alloc] initWithNibName:nil bundle:nil];
    controller.verify = false;
    [self presentViewController:controller animated:YES completion:nil];
    
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
{
    return YES;
}
@end
