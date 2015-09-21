//
//  RetrievalAppointmentResponseDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ErrorDTO.h"

@interface RetrievalAppointmentResponseDTO : NSObject

@property (nonatomic, strong) NSArray* retrieveAppointments;
@property (nonatomic, strong) NSString* lastSyncTime;
@property (nonatomic, strong) ErrorDTO* error;
@property (nonatomic, assign) BOOL      success;


@end
