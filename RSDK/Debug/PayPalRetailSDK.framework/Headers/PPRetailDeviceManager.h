/**
 * PPRetailDeviceManager.h
 *
 * DO NOT EDIT THIS FILE! IT IS AUTOMATICALLY GENERATED AND SHOULD NOT BE CHECKED IN.
 * Generated from: dist/transaction/DeviceManager.js
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
 * DeviceManager is responsible for exposing APIs regarding the devices.
 * Currently, you can use DeviceManager to prompt the List to select the device
 * or set/get the active device.
 */
@interface PPRetailDeviceManager : PPRetailObject


- (instancetype _Nullable)init;
    




/**
 * Search for readers according to the passed reader configuration
 */
-(void)searchAndConnect:(PPRetailReaderConfiguration* _Nullable)readerConfig callback:(PPRetailDeviceManagerConnectionHandler _Nullable)callback;

/**
 * Show a list of connected credit card readers.
 * If there is more than 1 devices. Select one of them to use it
 * for transaction.
 */
-(void)searchAndConnect:(PPRetailDeviceManagerConnectionHandler _Nullable)callback;

/**
 * Show a list of connected credit card readers.
 * If there is more than 1 devices. Select one of them to use it
 * for transaction.
 */
-(void)searchAndConnectWithoutCallback;

/**
 * Try connecting to the last active credit card reader
 */
-(void)connectToLastActiveReader:(PPRetailDeviceManagerConnectionHandler _Nullable)callback;

/**
 * Tries to connect to the previously used/active Bluetooth reader
 */
-(void)scanAndAutoConnectToBluetoothReader:(NSString* _Nullable)readerName callback:(PPRetailDeviceManagerConnectionHandler _Nullable)callback;

/**
 * Sets the active reader
 */
-(void)setActiveReader:(PPRetailPaymentDevice* _Nullable)pd;

/**
 * checks if any Miura devive is connected
 */
-(BOOL)isConnectedToMiura;

/**
 * Returns the selected device
 */
-(PPRetailPaymentDevice* _Nullable)getActiveReader;

/**
 * Get a list of paired/discovered devices
 */
-(NSArray* _Nullable)getDiscoveredDevices;

/**
 * Get the name of last active reader
 */
-(NSString* _Nullable)getLastActiveBluetoothReader;

/**
 * Get a list of paired devices
 */
-(void)getPairedBluetoothDevices:(PPRetailDeviceManagerPairedBTDevicesHandler _Nullable)callback;

/**
 * Stop scanning for Bluetooth devices
 * Use this API in conjunction with {@link #scanAndAutoConnectToBluetoothReader}
 */
-(void)stopScanningForBluetoothReaders;




/**
 * Add a listener for the deviceDiscovered event
 * @returns PPRetailDeviceDiscoveredSignal an object that can be used to remove the listener when
 * you're done with it.
 */
-(PPRetailDeviceDiscoveredSignal _Nullable)addDeviceDiscoveredListener:(PPRetailDeviceDiscoveredEvent _Nullable)listener;

/**
 * Remove a listener for the deviceDiscovered event given the signal object that was returned from addDeviceDiscoveredListener
 */
-(void)removeDeviceDiscoveredListener:(PPRetailDeviceDiscoveredSignal _Nullable)listenerToken;


@end
