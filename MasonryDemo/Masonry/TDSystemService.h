//
//  TDSystemService.h
//  Tudur
//
//  Created by WuHai on 15/3/10.
//  Copyright (c) 2015年 LZeal Information Technology Co.,Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <QiniuSDK.h>

@interface TDSystemService : NSObject

+ (void)saveIntroShowed;

+ (BOOL)hasIntroShowed;

/**
 *  上传图片
 *
 *  @param image    需要上传的image
 *  @param progress 上传进度block
 *  @param success  成功block 返回url地址
 *  @param failure  失败block
 */
+ (void)uploadImage:(UIImage *)image
           progress:(QNUpProgressHandler)progress
            success:(void (^)(NSString *url))success
            failure:(void (^)())failure;

// 上传多张图片,按队列依次上传
+ (void)uploadImages:(NSArray *)imageArray
            progress:(void (^)(CGFloat))progress
             success:(void (^)(NSArray *))success
             failure:(void (^)())failure;

// 获取七牛上传token
+ (void)getQiniuUploadToken:(void (^)(NSString *token))success failure:(void (^)())failure;

// 强制升级、启动页
+ (void)requestVersionUpdate:(void (^)(NSDictionary *dict))success failure:(void (^)())failure;

@end
