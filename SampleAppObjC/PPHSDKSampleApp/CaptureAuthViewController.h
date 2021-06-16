//
//  CaptureAuthViewController.h
//  PPHSDKSampleApp
//
//  Created by Patil, Mihir on 3/20/18.
//  Copyright © 2018 Patil, Mihir. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <PayPalRetailSDK/PayPalRetailSDK.h>

@interface CaptureAuthViewController : UIViewController

@property (nonatomic, assign) PPRetailRetailInvoice *invoice;
@property (nonatomic, assign) NSString *authTransactionNumber;
@property (nonatomic, assign) PPRetailInvoicePaymentMethod paymentMethod;
@property (nonatomic, assign) BOOL isTip;
@end
