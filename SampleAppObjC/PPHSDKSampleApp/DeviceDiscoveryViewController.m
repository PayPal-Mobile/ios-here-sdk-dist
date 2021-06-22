//
//  DeviceDiscoveryViewController.m
//  PPHSDKSampleApp
//
//  Created by Patil, Mihir on 3/19/18.
//  Copyright © 2018 Patil, Mihir. All rights reserved.
//

#import "DeviceDiscoveryViewController.h"
#import "UIButton+CustomButton.h"
#import <PayPalRetailSDK/PayPalRetailSDK.h>

@interface DeviceDiscoveryViewController ()
@property (weak, nonatomic) IBOutlet UIButton *goToPmtPageBtn;
@property (weak, nonatomic) IBOutlet UIButton *findAndConnect;
@property (weak, nonatomic) IBOutlet UITextView *findAndConnectCodeView;
@property (weak, nonatomic) IBOutlet UIButton *connectLastKnown;
@property (weak, nonatomic) IBOutlet UITextView *connectLastKnownCodeView;
@property (weak, nonatomic) IBOutlet UILabel *activeReaderLbl;
@property (weak, nonatomic) IBOutlet UISwitch *autoConnectReader;
@property (weak, nonatomic) IBOutlet UITextView *autoConnectReaderCodeView;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *autoConnectActivityIndicator;

@property PPRetailDeviceManager *deviceManager;
@end

@implementation DeviceDiscoveryViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setUpDefaultView];
    self.deviceManager = [PayPalRetailSDK deviceManager];
    
    // Watch for audio readers.
    // This will show a microphone connection permission prompt on the initial call (only once per app install)
    // Time this call such that it does not interfere with any other alerts
    // Requires a merchant, so start watching after a successful initializeMerchant
    // The audio reader may not be available to some merchants based on their location or other criteria
    // This is required if the app would like to use audio readers
    [PayPalRetailSDK startWatchingAudio];
}

// Function to search for connected devices and show the UI to select which
// device to use. As part of this function, we also need to include the process
// of reader updates for our BT readers.
- (IBAction)findAndConnectReader:(id)sender {
    
    [self.deviceManager searchAndConnect:^(PPRetailError *error, PPRetailPaymentDevice *cardReader) {
        if(error != nil) {
            NSLog(@"Search Device Error: %@",error.debugId);
            NSLog(@"Search Device Error: %@",error.code);
            NSLog(@"Search Device Error: %@",error.message);
            return;
        }
        
        if([cardReader isConnected]) {
            self.activeReaderLbl.text =[NSString stringWithFormat:@"Connected: %@ ",cardReader.id];
            [self checkForReaderUpdate:cardReader];
            self.goToPmtPageBtn.enabled = YES;
        }
    }];
}

// Function to connect to the last known reader device used and check for any
// reader updates.
- (IBAction)connectToLastReader:(id)sender {
    [self.deviceManager connectToLastActiveReader:^(PPRetailError *error, PPRetailPaymentDevice *cardReader) {
        if(error != nil) {
            NSLog(@"Connect Last Device Error: %@", error.debugId);
            NSLog(@"Connect Last Device Error: %@", error.code);
            NSLog(@"Connect Last Device Error: %@", error.message);
            self.activeReaderLbl.text  = [NSString stringWithFormat:@" Error: %@",error.message];
            return;
        }
        if(cardReader != nil && [cardReader isConnected]) {
            self.activeReaderLbl.text = [NSString stringWithFormat:@"Connected: %@ ",cardReader.id];
            [self checkForReaderUpdate:cardReader];
            self.goToPmtPageBtn.enabled = YES;
        }
    }];
}

/// Auto Connect to the last known reader. It will check for that reader in the
/// background and connect to it automatically if it is available.
- (IBAction)autoConnectReader:(UISwitch *)sender {
    if ([(UISwitch *)sender isOn] == YES) {
        [self autoConnectCallback:(UISwitch *)sender];
    } else {
        [self.deviceManager stopScanningForBluetoothReaders];
    }
}

-(void) autoConnectCallback:(UISwitch *) sender {
    [self.autoConnectActivityIndicator startAnimating];
    NSString *lastActiveReader = [self.deviceManager getLastActiveBluetoothReader];
    if([lastActiveReader isEqualToString:@""]) {
        [self.autoConnectActivityIndicator stopAnimating];
        self.activeReaderLbl.text = [NSString stringWithFormat:@"No last known reader. Please Connect first"];
        return;
    }
    [self.deviceManager scanAndAutoConnectToBluetoothReader:lastActiveReader callback:^(PPRetailError *error, PPRetailPaymentDevice *cardReader) {
        [self.autoConnectActivityIndicator stopAnimating];
        if(error != nil) {
            if ([self.deviceManager shouldStopScanning:error]) {
                self.activeReaderLbl.text = [NSString stringWithFormat:@"Stopping auto connect: Domain: %@\nCode: %@\nMessage: %@", error.domain, error.code, error.message];
                NSLog(@"Stopping auto connect: %@ %@ %@", error.domain, error.code, error.message);
            }
            dispatch_after(1, dispatch_get_main_queue(), ^(void) {
                [self autoConnectReader:(UISwitch *)sender];
            });
        } else {
            self.activeReaderLbl.text = [NSString stringWithFormat:@"Connected to: %@", cardReader.id];
            self.goToPmtPageBtn.enabled = YES;
        }
    }];
}

// Code that checks if there's a software update available for the connected
// reader and initiates the process if there's one available.
- (void)checkForReaderUpdate:(PPRetailPaymentDevice *) reader {
    
    if(reader != nil && [reader pendingUpdate] != nil && [[reader pendingUpdate] isRequired]) {
        [[reader pendingUpdate] offer:^(PPRetailError *error, BOOL deviceUpgraded) {
            if(deviceUpgraded) {
                NSLog(@"Reader update complete.");
            } else {
                NSLog(@"Error in offer step: %@", error.debugId);
                NSLog(@"Error in offer step: %@", error.code);
                NSLog(@"Error in offer step: %@", error.message);
            }
        }];
    } else {
        NSLog(@"Reader update not required at this time.");
    }
}

- (IBAction)goToPmtPage:(id)sender {
    [self performSegueWithIdentifier:@"goToPmtPage" sender:sender];
}

-(void)setUpDefaultView{
    // Setting up initial aesthetics
    self.goToPmtPageBtn.enabled = NO;
    self.activeReaderLbl.text = @"";
    [self.activeReaderLbl setTextColor:[UIColor blackColor]];
    self.findAndConnectCodeView.text = @"[self.deviceManager searchAndConnect:^(PPRetailError *error, PPRetailPaymentDevice *cardReader) {\n <code to handle success/failure> \n}];";
    self.connectLastKnownCodeView.text = @"[self.deviceManager connectToLastActiveReader:^(PPRetailError *error, PPRetailPaymentDevice *cardReader)  {\n <code to handle success/failure> \n}];";
    self.autoConnectReaderCodeView.text = @"[self.deviceManager scanAndAutoConnectToBluetoothReader:lastActiveReader callback:^(PPRetailError *error, PPRetailPaymentDevice *cardReader) {\n <code to handle success/failure> \n}];";
    
    [CustomButton customizeButton:_findAndConnect];
    [CustomButton customizeButton:_connectLastKnown];
    // [CustomButton customizeButton:_autoConnectReader];
}


@end
