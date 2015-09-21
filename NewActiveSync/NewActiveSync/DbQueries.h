//
//  DbQueries.h
//  ActiveSync
//
//  Created by Netvarth_Mac2 on 18/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#ifndef ActiveSync_DbQueries_h
#define ActiveSync_DbQueries_h

#define DATABASE_NAME @"ActiveSyncDatabase.sql"

//syncable_msg_tbl
#define CREATE_TABLE_SYNC @"CREATE TABLE if not exists syncable_msg_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT, category STRING, syncPriority STRING, passPhrase STRING, createDate STRING, cloudableData STRING, destination STRING, source STRING)"


#define INSERT_TABLE_SYNCABLE @"INSERT INTO syncable_msg_tbl (category, syncPriority, passPhrase, createDate, cloudableData, destination, source) VALUES (\"%@\", \"%@\", \"%@\", \"%@\", \"%@\", \"%@\", \"%@\")"

#define DELETE_SYNCABLE_USING_ID @"DELETE FROM syncable_msg_tbl WHERE id= %d"
#define GET_COUNT_OF_SYNCABLE_MSG_TBL @"SELECT COUNT(id) FROM syncable_msg_tbl"
#define SELECT_ALL_SYNCABLE_DETAILS @"SELECT * FROM syncable_msg_tbl"

//poller_status_tbl
#define CREATE_TABLE_POLLER_STATUS @"CREATE TABLE if not exists poller_status_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT, corporate_id STRING, branch_id STRING, device_id STRING, lastUpdatedTime STRING)"
//#define INSERT_POLLER_STATUS_TBL @"INSERT INTO poller_status_tbl (corporate_id, branch_id, device_id, lastUpdatedTime) VALUES (\"%@\", \"%@\", \"%@\", \"%@\")"
#define INSERT_POLLER_STATUS_TBL @"INSERT INTO poller_status_tbl (corporate_id, branch_id, device_id) VALUES (\"%@\", \"%@\", \"%@\")"
#define GET_COUNT_OF_POLLER_STATUS_TBL @"SELECT COUNT(id) FROM poller_status_tbl"
#define SELECT_CORPORATEID @"SELECT corporate_id FROM poller_status_tbl"
#define SELECT_BRANCHID @"SELECT branch_id FROM poller_status_tbl"
#define SELECT_DEVICEID @"SELECT device_id FROM poller_status_tbl"
#define SELECT_LASTUPDATEDTIME @"SELECT lastUpdatedTime FROM poller_status_tbl"
#define UPDATE_TIME @"UPDATE poller_status_tbl SET lastUpdatedTime = \"%@\" WHERE id = %d"

//poller_response_tbl
#define CREATE_TABLE_POLLER_RESPONSE @"CREATE TABLE if not exists poller_response_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT, cloudable_data_category, syncPriority, passPhrase, cloudable_data, created_date_time, sync_msg_status, destination)"

#define INSERT_TABLE_POLLER_RESPONSE_TBL @"INSERT INTO poller_response_tbl (cloudable_data_category, syncPriority, passPhrase, cloudable_data, created_date_time, sync_msg_status, destination) VALUES (\"%@\", \"%@\", \"%@\", \"%@\", \"%@\", \"%@\", \"%@\")"

#define DELETE_DATA_BY_ID @"DELETE FROM poller_response_tbl WHERE id= %d"



#endif
