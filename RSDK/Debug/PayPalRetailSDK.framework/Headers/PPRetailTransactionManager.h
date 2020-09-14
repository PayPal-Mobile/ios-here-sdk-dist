/**
 * PPRetailTransactionManager.h
 *
 * DO NOT EDIT THIS FILE! IT IS AUTOMATICALLY GENERATED AND SHOULD NOT BE CHECKED IN.
 * Generated from: dist/transaction/TransactionManager.js
 *
 * 
 */

#import "PayPalRetailSDKTypeDefs.h"
#import "PPRetailObject.h"


@class PPRetailSDK;
@class PPRetailError;
@class PPRetailPayPalErrorInfo;
@class PPRetailAccountSummary;
@class PPRetailAccountSummarySection;
@class PPRetailInvoiceAddress;
@class PPRetailInvoiceAttachment;
@class PPRetailInvoiceBillingInfo;
@class PPRetailInvoiceCCInfo;
@class PPRetailCountries;
@class PPRetailCountry;
@class PPRetailInvoiceCustomAmount;
@class PPRetailInvoice;
@class PPRetailInvoiceActions;
@class PPRetailInvoiceConstants;
@class PPRetailInvoiceListRequest;
@class PPRetailInvoiceListResponse;
@class PPRetailInvoiceMetaData;
@class PPRetailInvoiceTemplatesResponse;
@class PPRetailInvoicingService;
@class PPRetailInvoiceItem;
@class PPRetailInvoiceMerchantInfo;
@class PPRetailInvoiceNotification;
@class PPRetailInvoicePayment;
@class PPRetailInvoicePaymentTerm;
@class PPRetailInvoiceRefund;
@class PPRetailInvoiceSearchRequest;
@class PPRetailInvoiceShippingInfo;
@class PPRetailInvoiceTemplate;
@class PPRetailInvoiceTemplateSettings;
@class PPRetailMerchant;
@class PPRetailNetworkRequest;
@class PPRetailNetworkResponse;
@class PPRetailSdkEnvironmentInfo;
@class PPRetailRetailInvoice;
@class PPRetailRetailInvoicePayment;
@class PPRetailBraintreeManager;
@class PPRetailSimulationManager;
@class PPRetailMerchantManager;
@class PPRetailCaptureHandler;
@class PPRetailTransactionContext;
@class PPRetailTransactionManager;
@class PPRetailTransactionBeginOptions;
@class PPRetailReceiptDestination;
@class PPRetailDeviceManager;
@class PPRetailSignatureReceiver;
@class PPRetailReceiptOptionsViewContent;
@class PPRetailReceiptEmailEntryViewContent;
@class PPRetailReceiptSMSEntryViewContent;
@class PPRetailReceiptViewContent;
@class PPRetailOfflinePaymentStatus;
@class PPRetailOfflinePaymentInfo;
@class PPRetailOfflineTransactionRecord;
@class PPRetailTokenExpirationHandler;
@class PPRetailCard;
@class PPRetailBatteryInfo;
@class PPRetailMagneticCard;
@class PPRetailPaymentDevice;
@class PPRetailManuallyEnteredCard;
@class PPRetailDeviceUpdate;
@class PPRetailCardInsertedHandler;
@class PPRetailDeviceStatus;
@class PPRetailPayer;
@class PPRetailTransactionRecord;
@class PPRetailVaultRecord;
@class PPRetailAuthorizedTransaction;
@class PPRetailPage;
@class PPRetailDiscoveredCardReader;
@class PPRetailCardReaderScanAndDiscoverOptions;
@class PPRetailDeviceConnectorOptions;
@class PPRetailReaderConfiguration;
@class PPRetailSimulationOptions;

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/**
 * TransactionManager is a public facing facade to everything related to a Transaction.
 */
@interface PPRetailTransactionManager : PPRetailObject






/**
 * Create a transaction using the provided Invoice. An existing transaction will be canceled
 */
-(void)createTransaction:(PPRetailInvoice* _Nullable)invoice callback:(PPRetailTransactionManagerTransactionHandler _Nullable)callback;

/**
 * Create a vault.
 */
-(void)createVaultTransaction:(PPRetailTransactionManagerTransactionHandler _Nullable)callback;

/**
 * Create a refund transaction. An existing transaction will be canceled.
 * Note: Refunds can be performed using invoiceId alone using createRefundTransactionWithInvoiceId.
 * And refunds can also be performed with transactionNumber alone using createRefundTransactionWithTransactionNumber.
 */
-(void)createRefundTransaction:(NSString* _Nullable)invoiceId transactionNumber:(NSString* _Nullable)transactionNumber paymentMethod:(PPRetailInvoicePaymentMethod)paymentMethod callback:(PPRetailTransactionManagerTransactionHandler _Nullable)callback;

/**
 * Simplified cash or check refund with invoiceId. An existing transaction will be canceled.
 */
-(void)createCashOrCheckRefundTransaction:(NSString* _Nullable)invoiceId callback:(PPRetailTransactionManagerTransactionHandler _Nullable)callback;

/**
 * Simplified card refund with invoiceId. An existing transaction will be canceled.
 */
-(void)createCardRefundTransaction:(NSString* _Nullable)invoiceId callback:(PPRetailTransactionManagerTransactionHandler _Nullable)callback;

/**
 * Enable the offline payment flag and start the offline payment process if needed
 */
-(void)startOfflinePayment:(PPRetailTransactionManagerOfflinePaymentStatusHandler _Nullable)callback;

/**
 * Get offline payment eligibility for the merchant
 */
-(BOOL)getOfflinePaymentEligibility;

/**
 * disable the offline payment flag
 */
-(void)stopOfflinePayment:(PPRetailTransactionManagerOfflinePaymentStatusHandler _Nullable)callback;

/**
 * start the replay of the offline txns saved
 */
-(void)startReplayOfflineTxns:(PPRetailTransactionManagerOfflinePaymentStatusHandler _Nullable)callback;

/**
 * stop the replay of the offline txns saved
 */
-(void)stopReplayOfflineTxns:(PPRetailTransactionManagerOfflinePaymentStatusHandler _Nullable)callback;

/**
 * get the status of offline payment txns
 */
-(void)getOfflinePaymentStatus:(PPRetailTransactionManagerOfflinePaymentStatusHandler _Nullable)callback;

/**
 * Enable the offline payment flag
 */
-(BOOL)getOfflinePaymentEnabled;

/**
 * Get the current transaction context
 */
-(PPRetailTransactionContext* _Nullable)getCurrentTransactionContext;

/**
 * Retrieve the list of authorized transactions.
 */
-(void)retrieveAuthorization:(NSDate* _Nullable)startDateTime endDateTime:(NSDate* _Nullable)endDateTime pageSize:(int)pageSize status:(NSArray* _Nullable)status callback:(PPRetailTransactionManagerRetrieveAuthorizedTransactionsHandler _Nullable)callback;

/**
 * Retrieve the next list of authorized transactions using the nextPageToken.
 */
-(void)retrieveAuthorizationUsingToken:(NSString* _Nullable)nextPageToken callback:(PPRetailTransactionManagerRetrieveAuthorizedTransactionsHandler _Nullable)callback;

/**
 * Void an authorized transaction
 */
-(void)voidAuthorization:(NSString* _Nullable)authorizationId callback:(PPRetailTransactionManagerVoidAuthorizationHandler _Nullable)callback;

/**
 * Capture a previously authorized transaction.
 */
-(void)captureAuthorization:(NSString* _Nullable)authorizationId invoiceId:(NSString* _Nullable)invoiceId totalAmount:(NSDecimalNumber* _Nullable)totalAmount gratuityAmount:(NSDecimalNumber* _Nullable)gratuityAmount currency:(NSString* _Nullable)currency callback:(PPRetailTransactionManagerCaptureAuthorizedTransactionHandler _Nullable)callback;

/**
 * Capture a previously authorized transaction.
 */
-(void)captureAuthorization:(NSString* _Nullable)authorizationId invoiceId:(NSString* _Nullable)invoiceId totalAmount:(NSDecimalNumber* _Nullable)totalAmount gratuityAmount:(NSDecimalNumber* _Nullable)gratuityAmount currency:(NSString* _Nullable)currency base64SignatureJpeg:(NSString* _Nullable)base64SignatureJpeg callback:(PPRetailTransactionManagerCaptureAuthorizedTransactionHandler _Nullable)callback;




@end
