#import <UIKit/UIKit.h>
#import <SMPageControl/SMPageControl.h>

@class XNLoopBannerView;
@protocol XNLoopBannerViewDelegate <NSObject>
@optional
- (void)bannerView:(XNLoopBannerView *)bannerView didSelectAtIndex:(NSInteger)index;

@end

@interface XNLoopBannerView : UIView

@property(nonatomic, weak) id<XNLoopBannerViewDelegate> bannerDelegate;
@property(nonatomic, strong, readonly) SMPageControl *pageControl;
@property(nonatomic) NSInteger currentPage; //default is 0.
@property(nonatomic) BOOL autoScroll; //default is YES.
@property(nonatomic) NSTimeInterval animationDuration; //default is 3s.
@property(nonatomic, strong) UIImage *placeholderImage;

/**
 *  do NOT use ".pageControl.frame = " to change frame of pageControl. Default is CGRectMake(0,
 *  self.frame.size.height - 22, self.frame.size.width, 22).
 */
@property(nonatomic) CGRect pageControlFrame;

//  object in "imageUrls" must be kind of NSString or NSURL class"
- (instancetype)initWithFrame:(CGRect)frame imageUrls:(NSArray *)imageUrls;
- (void)reloadWithImageUrls:(NSArray *)imageUrls;

- (void)setCurrentPage:(NSInteger)currentPage animated:(BOOL)animated;

@end