//
//  AMBubbleGlobals.h
//  BubbleTableDemo
//
//  Created by Andrea Mazzini on 30/06/13.
//  Copyright (c) 2013 Andrea Mazzini. All rights reserved.
//

typedef enum {
	AMBubbleTableStyleDefault,
	AMBubbleTableStyleSquare,
	AMBubbleTableStyleFlat
} AMBubbleTableStyle;

typedef enum {
	AMBubbleCellTimestamp,
	AMBubbleCellSent,
	AMBubbleCellReceived
} AMBubbleCellType;

typedef enum {
	AMBubbleAccessoryUp,
	AMBubbleAccessoryDown
} AMBubbleAccessoryPosition;

#define kMessageTextWidth	180.0f

#ifdef __IPHONE_6_0
# define ALIGN_CENTER NSTextAlignmentCenter
#else
# define ALIGN_CENTER UITextAlignmentCenter
#endif

@protocol AMBubbleTableDataSource <NSObject>
@required
- (NSInteger)numberOfRows;
- (AMBubbleCellType)cellTypeForRowAtIndexPath:(NSIndexPath *)indexPath;
- (NSString *)textForRowAtIndexPath:(NSIndexPath *)indexPath;
- (NSDate *)timestampForRowAtIndexPath:(NSIndexPath *)indexPath;
@optional
- (UIImage*)avatarForRowAtIndexPath:(NSIndexPath *)indexPath;
- (NSString*)usernameForRowAtIndexPath:(NSIndexPath *)indexPath;
- (UIColor*)usernameColorForRowAtIndexPath:(NSIndexPath *)indexPath;
@end

@protocol AMBubbleTableDelegate <NSObject>
- (void)didSendText:(NSString*)text;
@end

@protocol AMBubbleAccessory <NSObject>
@required
- (id)setOptions:(NSDictionary*)options;
- (void)setupView:(NSDictionary*)params;
@end

/* Options */

// Enables the short timestamp for every single message
FOUNDATION_EXPORT NSString *const AMOptionsTimestampEachMessage;

// Short Timestamp font
FOUNDATION_EXPORT NSString *const AMOptionsTimestampShortFont;

// Full timestamp font
FOUNDATION_EXPORT NSString *const AMOptionsTimestampFont;

// Avatar size
FOUNDATION_EXPORT NSString *const AMOptionsAvatarSize;

// Accessory class. Pass your custom accessory view's name as string
FOUNDATION_EXPORT NSString *const AMOptionsAccessoryClass;

// Accessory view size. Needed to get the cell height, adjust this when using a custom BubbleAccessory. The default view defaults to the Avatar Size
FOUNDATION_EXPORT NSString *const AMOptionsAccessorySize;

// Margin height for the bubble accessory view
FOUNDATION_EXPORT NSString *const AMOptionsAccessoryMargin;

// Full timestamp height
FOUNDATION_EXPORT NSString *const AMOptionsTimestampHeight;

// Incoming bubble image
FOUNDATION_EXPORT NSString *const AMOptionsImageIncoming;

// Outgoing bubble image
FOUNDATION_EXPORT NSString *const AMOptionsImageOutgoing;

// Text bar background image
FOUNDATION_EXPORT NSString *const AMOptionsImageBar;

// Text bar front image
FOUNDATION_EXPORT NSString *const AMOptionsImageInput;

// Button image
FOUNDATION_EXPORT NSString *const AMOptionsImageButton;

// Button higlighted image
FOUNDATION_EXPORT NSString *const AMOptionsImageButtonHighlight;

// Textfield background
FOUNDATION_EXPORT NSString *const AMOptionsTextFieldBackground;

// Textfield font
FOUNDATION_EXPORT NSString *const AMOptionsTextFieldFont;

// Textfield font color
FOUNDATION_EXPORT NSString *const AMOptionsTextFieldFontColor;

// Table background
FOUNDATION_EXPORT NSString *const AMOptionsTableBackground;

// Accessory position (enum AMBubbleAccessoryPosition)
FOUNDATION_EXPORT NSString *const AMOptionsAccessoryPosition;

// Button Y offset
FOUNDATION_EXPORT NSString *const AMOptionsButtonOffset;

// Bubble text color
FOUNDATION_EXPORT NSString *const AMOptionsBubbleTextColor;

// Bubble text font
FOUNDATION_EXPORT NSString *const AMOptionsBubbleTextFont;

// Username text font
FOUNDATION_EXPORT NSString *const AMOptionsUsernameFont;

@interface AMBubbleGlobals : NSObject

+ (NSDictionary*)defaultOptions;

// Styles
+ (NSDictionary*)defaultStyleDefault;
+ (NSDictionary*)defaultStyleSquare;
+ (NSDictionary*)defaultStyleFlat;

@end