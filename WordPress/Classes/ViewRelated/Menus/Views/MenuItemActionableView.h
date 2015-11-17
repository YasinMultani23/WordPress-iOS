#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger) {
    MenuItemActionableIconNone,
    MenuItemActionableIconDefault,
    MenuItemActionableIconEdit,
    MenuItemActionableIconAdd,
}MenuItemActionableIconType;

extern CGFloat const MenuItemActionableViewDefaultHeight;
extern CGFloat const MenuItemActionableViewAccessoryButtonHeight;

@protocol MenuItemDrawingViewDelegate <NSObject>
- (void)drawingViewDrawRect:(CGRect)rect;
@end

@interface MenuItemDrawingView : UIView

@end

@interface MenuItemActionableView : UIView <MenuItemDrawingViewDelegate>

@property (nonatomic, strong) MenuItemDrawingView *contentView;
@property (nonatomic, weak) MenuItemActionableView *previousView;
@property (nonatomic, weak) MenuItemActionableView *nextView;
@property (nonatomic, assign) BOOL highlighted;
@property (nonatomic, assign) NSUInteger indentationLevel;
@property (nonatomic, strong) UIStackView *stackView;
@property (nonatomic, strong) UILabel *textLabel;
@property (nonatomic, strong) UIImageView *iconView;
@property (nonatomic, assign) MenuItemActionableIconType iconType;

- (void)addAccessoryButton:(UIButton *)button;
- (UIButton *)addAccessoryButtonIconViewWithType:(MenuItemActionableIconType)type;

// called on init and when highlighted value changes
- (UIColor *)contentViewBackgroundColor;
- (UIColor *)textLabelColor;
- (UIColor *)iconTintColor;

@end
