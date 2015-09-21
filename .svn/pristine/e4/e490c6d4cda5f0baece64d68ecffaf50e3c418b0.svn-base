//
//  EncryptionController.m
//  netMDnew
//  Coded by Fairborn
//  Created by Remesh Kuruppath on 8/11/14.
//  Copyright (c) 2014 Netvarth. All rights reserved.
//

/*
 This class is used to encrypt the password>The algorithm followed is AES.Among different types of encryption using AES algorithm(ie,encryption with key,encryption with static key...etc),we followed encryption with key.The Key is the encrypted first using MD5 heaping and used used for final encryption.
 */

#import "EncryptionController.h"

@implementation EncryptionController


/*
 *Method to encrypt the password
 *returns the nsdata after encryption
 */
- (NSData *) encrypt:(NSString *) dataToEncrypt
{
    
    //appending the string "nvKey" into the password
    NSString* key = [dataToEncrypt stringByAppendingString:@"nvKey"];
    NSData* rawKey = [self passWordToKey:key];
    NSUInteger data_length= [dataToEncrypt length];
    size_t numBytesEncrypted = 0;
    char* keyAftrEncoding =[dataToEncrypt cStringUsingEncoding:NSISOLatin1StringEncoding];
    NSData *keyData=[NSData dataWithBytes:keyAftrEncoding length:strlen(keyAftrEncoding)];
    NSLog(@"KeyData:%@",keyData);
    size_t buffer_size           = data_length + kCCBlockSizeAES128;
    void* buffer                 = malloc(buffer_size);
    
    
    
    CCCryptorStatus cryptStatus = CCCrypt(kCCEncrypt,
                                          kCCAlgorithmAES128,
                                          kCCOptionPKCS7Padding,
                                          rawKey.bytes,
                                          rawKey.length,
                                          NULL /* initialization vector (optional) */,
                                          [keyData bytes ],
                                          data_length, /* input */
                                          buffer,
                                          buffer_size, /* output */
                                          &numBytesEncrypted);
    
    
    NSLog(@"~~num bytes encrypted: %ld",numBytesEncrypted);
    if (cryptStatus == kCCSuccess){
        NSLog(@"~~Data encoded successfully...");
        return [NSData dataWithBytesNoCopy:buffer length:numBytesEncrypted];
    }
    
    free(buffer);
    
    
    return nil;
}

/*
 *method to perform MD5 hashing on  key.
 *The MD5 message-digest algorithm is a widely used cryptographic hash function producing a 128-bit (16 byte) * hash value, typically expressed in text format as a 32 digit hexadecimal number
 *returnd the nsdata
 */
- (NSData*) passWordToKey:(NSString*) key
{
    //char* s =[key cStringUsingEncoding:NSUTF8StringEncoding];
    char* keyAftrEncoding =[key cStringUsingEncoding:NSISOLatin1StringEncoding];
    NSData *keyData=[NSData dataWithBytes:keyAftrEncoding length:strlen(keyAftrEncoding)];
    //NSLog(@"%@",keyData);
    uint8_t digest[CC_MD5_DIGEST_LENGTH]={0};
    CC_MD5(keyData.bytes, keyData.length, digest);
    NSData *out=[NSData dataWithBytes:digest length:CC_MD5_DIGEST_LENGTH];
    NSString *hash=[out description];
    NSLog(@"%@",out);
    NSLog(@"%@",hash);
    return out;
    
}


@end
