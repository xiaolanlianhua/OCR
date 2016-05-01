#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#pragma mark - Invaliables

typedef enum {
	QH_PIXEL_GRAYSCALE =			0,
	QH_PIXEL_COLOR =				1 << 0,
	QH_PIXEL_ANYCOLOR =				1 << 1,
}QH_PIXEL_TYPE;

typedef enum {
	QH_BYTES_PER_PIXEL_UNKNOWN =	0,
	QH_BYTES_PER_PIXEL_8BIT =		1,
	QH_BYTES_PER_PIXEL_16BIT =		2,
	QH_BYTES_PER_PIXEL_24BIT =		3,
	QH_BYTES_PER_PIXEL_32BIT =		4,
}QH_BYTES_PER_PIXEL;

#define QH_DEFAULT_ALPHA_VALUE		0xff

#define QH_DEFAULT_JPG_QUALITY		1.0

#pragma mark - UIImage category

@interface UIImage(QuartzHelpLibrary)
- (NSData*)PNGRepresentaion;
- (NSData*)JPEGRepresentaion;
- (NSData*)JPEGRepresentaionWithCompressionQuality:(float)compressionQuality;
- (UIImage*)getRotatedImage;
- (UIImage*)getRotatedImageWithResizing:(float)scale;
- (CGImageRef)createCGImageRotated;
- (CGImageRef)createCGImageRotatedWithResizing:(float)scale;
@end

#ifdef __cplusplus
extern "C" {
#endif

#pragma mark - Load image file

CGImageRef CGImageCreateWithPNGorJPEGFilePath(CFStringRef filePath);

#pragma mark - Dump CGImage information

void CGImageDumpImageInformation(CGImageRef imageRef);

#pragma mark - Read pixel from CGImage

void CGCreatePixelBufferWithImage(CGImageRef imageRef, unsigned char **pixel, int *width, int *height, int *bytesPerPixel, QH_PIXEL_TYPE pType);

#pragma mark - Creating CGImage

CGImageRef CGImageCreateWithPixelBuffer(unsigned char *pixel, int width, int height, int bytesPerPixel, QH_PIXEL_TYPE target_pType);

#pragma mark - Convert CGImage to image file binary

NSData* CGImageGetPNGPresentation(CGImageRef imageRef);
NSData* CGImageGetJPEGPresentation(CGImageRef imageRef);

#pragma mark - Resize

CGImageRef CGImageCreateWithResizing(CGImageRef imageRef, float scale);
	
#ifdef __cplusplus
}
#endif