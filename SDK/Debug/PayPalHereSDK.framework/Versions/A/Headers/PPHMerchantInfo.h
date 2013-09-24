//
//  PayPalHereSDK
//
//  Copyright (c) 2012 PayPal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PPHInvoiceContactInfo.h"

@class PPHAccessAccount;
@class PPHPaymentLimits;

/*!
 * Information about the merchant's preferences such as currency and invoice header information.
 */
@interface PPHMerchantInfo : NSObject <NSCoding>

/*!
 * The image to be displayed on invoices
 */
@property (nonatomic,strong) NSURL* invoiceLogoUrl;
/*!
 * The contact info to be used on invoices as the "From" information
 */
@property (nonatomic,strong) PPHInvoiceContactInfo* invoiceContactInfo;

/*!
 * The currency code for invoices from the merchant. We don't currently support the currency NOT being the
 * default currency of the account.
 */
@property (nonatomic,strong) NSString* currencyCode;

/*!
 * Access credentials from PayPal Access
 */
@property (nonatomic,strong) PPHAccessAccount* payPalAccount;

@end
