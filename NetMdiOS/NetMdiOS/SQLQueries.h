//
//  SQLQueries.h
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 15/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#ifndef NetMdiOS_SQLQueries_h
#define NetMdiOS_SQLQueries_h
#define DATABASE_NAME   @"NetMDDatabase.sql"

//login_tbl
#define CREATE_TABLE_LOGIN @"CREATE TABLE if not exists login_tbl (login_tbl_id INTEGER PRIMARY KEY AUTOINCREMENT,login_name STRING, password STRING, user_type STRING)"

#define INSERT_TABLE_LOGIN @"INSERT INTO login_tbl (login_name, password, user_type) VALUES (\"%@\", \"%@\", \"%@\")"

#define INSERT_USER_LOGIN @"INSERT INTO login_tbl (login_name , user_type , password) VALUES (\"%@\", \"%@\", \"%@\")"

#define SELECT_LOGIN_BY_USERNAME @"SELECT * FROM login_tbl WHERE login_name = \"%@\""

#define SELECT_USERID_USERNAME @"SELECT login_tbl_id FROM login_tbl WHERE login_name = \"%@\""
#define SELECT_ALL_USERNAME @"SELECT * FROM login_tbl"

//result_tbl
#define CREATE_TABLE_RESULTS @"CREATE TABLE if not exists result_tbl (patient_id INTEGER, doctor_id INTEGER, result TEXT, lab_branch_id INTEGER,lab_order_id INTEGER PRIMARY KEY, FOREIGN KEY(patient_id) REFERENCES patient_tbl(id), FOREIGN KEY(doctor_id) REFERENCES doctor_tbl(id))"

//sync_tbl
#define CREATE_TABLE_SYNC @"CREATE TABLE if not exists sync_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT,downloaded_time STRING,uploaded_time STRING)"
#define SELECT_SYNC_TABLE @"SELECT * FROM sync_tbl WHERE id = (SELECT MAX(id) FROM sync_tbl)"

#define UPDATE_SYNCTABLE_BY_UPLOADEDTIME @"UPDATE sync_tbl SET uploaded_time=\"%@\"  WHERE  id = (SELECT MAX(id) FROM sync_tbl)"
#define UPDATE_SYNCTABLE_BY_DOWNLOADEDTIME @"UPDATE sync_tbl SET downloaded_time=\"%@\"  WHERE  id = (SELECT MAX(id) FROM sync_tbl)"

#define UPDATE_SYNCTABLE_BY_FIRST_DOWNLOADEDTIME @"INSERT INTO sync_tbl (uploaded_time, downloaded_time) VALUES (\"%@\", \"%@\")"
//#define INSERT_TABLE_SYNC "INSERT INTO sync_tbl (downloaded_time,uploaded_time) VALUES (\"%@\", \"%@\")"

// OWNER (netmd_tbl)
#define	ENCRYPT_PASS_KEY		@"nstFYd+GqaIarP/lz5nUeA=="

#define CREATE_TABLE_NETMD @"CREATE TABLE if not exists netmd_tbl  (id INTEGER PRIMARY KEY AUTOINCREMENT, owner_first_name STRING, name STRING, owner_address STRING, owner_email STRING, owner_phone STRING, owner_mobile STRING, login_id INTEGER,status STRING, owner_last_name STRING, head_office_name STRING, head_office_address STRING, head_office_phone STRING, head_office_mobile STRING, head_office_email STRING, created_time STRING, updated_time STRING, global_id INTEGER)"

//netmd_passphrase_tbl
#define CREATE_TABLE_PASSPHRASE @"CREATE TABLE if not exists netmd_passphrase_tbl(id INTEGER PRIMARY KEY AUTOINCREMENT,mac_id STRING,pass_phrase STRING,netmd_branch_id INTEGER,primary_key STRING,netmd_id INTEGER,dev_id STRING,FOREIGN KEY(netmd_id) REFERENCES netmd_tbl(id),FOREIGN KEY(netmd_branch_id) REFERENCES netmd_branch_tbl(id))"

#define INSERT_TABLE_PASSPHRASE @"INSERT INTO netmd_passphrase_tbl(mac_id,pass_phrase,netmd_branch_id,netmd_id,dev_id) VALUES (\"%@\", \"%@\",%d,%d,\"%@\")"

//netmd_branch_tbl
#define CREATE_TABLE_NETMD_BRANCH_TABLE @"CREATE TABLE if not exists netmd_branch_tbl(id INTEGER PRIMARY KEY AUTOINCREMENT,name STRING,address STRING,netmd_id INTEGER,phone STRING,mobile STRING,email STRING,status STRING,create_date_time STRING,update_date_time STRING,global_id INTEGER, FOREIGN KEY(netmd_id) REFERENCES netmd_tbl(id) )"

#define INSERT_TABLE_NETMD @"INSERT INTO netmd_tbl (owner_first_name, name, owner_address, owner_email,  owner_phone, owner_mobile, login_id, status , owner_last_name,head_office_name,head_office_address,head_office_phone ,head_office_mobile,head_office_email,global_id) VALUES (\"%@\", \"%@\", \"%@\", \"%@\", \"%@\", \"%@\",%d, \"%@\", \"%@\", \"%@\", \"%@\",\"%@\",\"%@\",\"%@\",%d)"

#define SELECT_NETMD_ID_FROM_NETMD_BRANCH_TABLE @"SELECT netmd_id FROM netmd_branch_tbl"
#define SELECT_MACID_FROM_NETMD_PASSPHRASE_TABLE @"SELECT mac_id FROM netmd_passphrase_tbl"
#define SELECT_GLOBALID_FROM_NETMD_BRANCH_TABLE @"SELECT global_id FROM netmd_branch_tbl"
#define SELECT_DEVID_FROM_NETMD_PASSPHRASE_TABLE @"SELECT dev_id FROM netmd_passphrase_tbl"

//#define SELECT_TABLE_NETMD @"SELECT * FROM

#define INSERT_TABLE_NETMD_BRANCH_TABLE @"INSERT INTO netmd_branch_tbl(name,address ,netmd_id ,phone,mobile,email,status ,create_date_time ,update_date_time,global_id)VALUES (\"%@\", \"%@\",%d,\"%@\", \"%@\", \"%@\", \"%@\",\"%@\",\"%@\",%d)"

#define SELECT_NETMDID_FROM_NETMDTABLE @"SELECT * FROM netmd_tbl WHERE global_id = %d"
#define SELECT_NETMDBRID_FROM_NETMDBRANCHTABLE @"SELECT * FROM netmd_branch_tbl WHERE global_id = %d"

#define SELECT_OWNER_FROM_NETMDTABLE @"SELECT * FROM netmd_tbl WHERE login_id = %d"
#define SELECT_PASSPHRASE @"SELECT pass_phrase FROM netmd_passphrase_tbl"
//admin
#define SELECT_LOGIN_BY_USERID @"SELECT * FROM login_tbl WHERE login_tbl_id = %d"

//Login Table
#define UPDATE_PASSWORD_OF_LOGINTABLE_BY_EMAILID @"UPDATE login_tbl SET password= \"%@\"  WHERE login_name=\"%@\""

// DOCTOR
#define CREATE_TABLE_DOCTOR @"CREATE TABLE if not exists doctor_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT, first_name STRING, last_name STRING, gender STRING, email STRING, address STRING, destignation STRING,login_table_id INTEGER, global_id INTEGER, consultation_interval INTEGER, mobile STRING, phone STRING,date_of_birth STRING,status STRING,created_time STRING,updated_time STRING, working_places STRING, work_history STRING, uniqueId STRING, FOREIGN KEY(login_table_id) REFERENCES login_tbl(login_id))"

#define INSERT_TABLE_DOCTOR @"INSERT INTO doctor_tbl (first_name, last_name, date_of_birth, destignation,  phone, mobile, email, gender ,global_id, login_table_id,address,created_time,updated_time,status,uniqueId) VALUES (\"%@\", \"%@\", \"%@\", \"%@\", \"%@\", \"%@\", \"%@\", \"%@\",%d,%d, \"%@\", \"%@\", \"%@\",\"%@\",\"%@\")"

#define SELECT_ALL_DOCTOR @"SELECT * FROM doctor_tbl ORDER BY first_name"
#define SELECT_LOGIN_ID @"SELECT login_table_id FROM doctor_tbl WHERE id=%d"
#define SELECT_UNIQUE_ID @"SELECT * FROM doctor_tbl WHERE id=%d"

//syncing create doctor list
//#define SELECT_ALL_DOCTOR_BY_GLOBALID @"SELECT * FROM doctor_tbl  WHERE global_id = %d "

#define SELECT_ALL_DOCTOR_BY_GLOBALID @"SELECT * FROM doctor_tbl LEFT OUTER JOIN login_tbl  ON doctor_tbl.login_table_id=login_tbl.login_tbl_id WHERE doctor_tbl.global_id=%d"


#define SELECT_ALL_DOCTOR_EXPERIENCE_BY_GLOBALID @"SELECT * FROM doctor_practice_experience_tbl LEFT OUTER JOIN doctor_tbl  ON doctor_tbl.id=doctor_practice_experience_tbl.doctor_id WHERE doctor_tbl.global_id=0 AND doctor_practice_experience_tbl.doctor_id=%d"
#define UPDATE_ALL_DOCTOR_EXPERIENCE_BY_GLOBALID @"SELECT * FROM doctor_practice_experience_tbl LEFT OUTER JOIN doctor_tbl  ON doctor_tbl.id=doctor_practice_experience_tbl.doctor_id WHERE doctor_tbl.global_id!=0 AND doctor_practice_experience_tbl.doctor_id=%d"
#define UPDATE_DOCTOR_TABLE_BY_GLOBALID @"UPDATE doctor_tbl SET global_id=%d WHERE  id=%d"

#define SELECT_ALL_UPDATED_DOCTORS_BY_GLOBALID @"SELECT * FROM doctor_tbl LEFT OUTER JOIN login_tbl  ON doctor_tbl.login_table_id=login_tbl.login_tbl_id LEFT OUTER JOIN sync_tbl  WHERE doctor_tbl.global_id!=0 AND doctor_tbl.updated_time>doctor_tbl.created_time AND doctor_tbl.updated_time> sync_tbl.uploaded_time AND doctor_tbl.status!=\"%@\""

//#define SELECT_HEADER_INFORMATION @"SELECT * FROM netmd_passphrase_tbl LEFT OUTER JOIN netmd_tbl  ON netmd_tbl.id=netmd_passphrase_tbl.netmd_id LEFT OUTER JOIN netmd_branch_tbl ON netmd_branch_tbl.id=netmd_passphrase_tbl.netmd_branch_id"
#define SELECT_HEADER_INFORMATION @"SELECT * FROM netmd_passphrase_tbl"

#define SELECT_ALL_DOCTOR_QUALIFICATIONS_BY_GLOBALID @"SELECT * FROM doctor_educational_qualification_tbl LEFT OUTER JOIN doctor_tbl  ON doctor_tbl.id=doctor_educational_qualification_tbl.doctor_id WHERE doctor_tbl. =0 AND doctor_educational_qualification_tbl.doctor_id=%d"
#define UPDATE_ALL_DOCTOR_QUALIFICATIONS_BY_GLOBALID @"SELECT * FROM doctor_educational_qualification_tbl LEFT OUTER JOIN doctor_tbl  ON doctor_tbl.id=doctor_educational_qualification_tbl.doctor_id WHERE doctor_tbl.global_id!=0 AND doctor_educational_qualification_tbl.doctor_id=%d"

#define SELECT_ALL_DOCTOR_ACHIEVEMENTS_BY_GLOBALID @"SELECT * FROM doctor_achievement_tbl LEFT OUTER JOIN doctor_tbl  ON doctor_tbl.id=doctor_achievement_tbl.doctor_id WHERE doctor_tbl.global_id=0 AND doctor_achievement_tbl.doctor_id=%d"
#define UPDATE_ALL_DOCTOR_ACHIEVEMENTS_BY_GLOBALID @"SELECT * FROM doctor_achievement_tbl LEFT OUTER JOIN doctor_tbl  ON doctor_tbl.id=doctor_achievement_tbl.doctor_id WHERE doctor_tbl.global_id!=0 AND doctor_achievement_tbl.doctor_id=%d"


#define SELECT_ALL_DOCTOR_MEMBERSHIPS_BY_GLOBALID @"SELECT * FROM doctor_membership_tbl LEFT OUTER JOIN doctor_tbl  ON doctor_tbl.id=doctor_membership_tbl.doctor_id WHERE doctor_tbl.global_id=0 AND doctor_membership_tbl.doctor_id=%d"
#define UPDATE_ALL_DOCTOR_MEMBERSHIPS_BY_GLOBALID @"SELECT * FROM doctor_membership_tbl LEFT OUTER JOIN doctor_tbl  ON doctor_tbl.id=doctor_membership_tbl.doctor_id WHERE doctor_tbl.global_id!=0 AND doctor_membership_tbl.doctor_id=%d"


#define UPDATE_ALL_DOCTOR_EXPERTISE_BY_GLOBALID @"SELECT * FROM doctor_expertise_tbl LEFT OUTER JOIN doctor_tbl  ON doctor_tbl.id=doctor_expertise_tbl.doctor_id WHERE doctor_tbl.global_id!=0 AND doctor_expertise_tbl.doctor_id=%d"
#define SELECT_ALL_DOCTOR_EXPERTISE_BY_GLOBALID @"SELECT * FROM doctor_expertise_tbl LEFT OUTER JOIN doctor_tbl  ON doctor_tbl.id=doctor_expertise_tbl.doctor_id WHERE doctor_tbl.global_id=0 AND doctor_expertise_tbl.doctor_id=%d"

#define CHECK_DOCTOR_EXIST_USING_UNIQUEID @"SELECT * FROM doctor_tbl WHERE uniqueId = \"%@\""

//updatedoctortime
#define EDIT_DOCTOR_BY_TIME_WHEN_GETUPDATED @"UPDATE doctor_tbl SET updated_time = \"%@\" WHERE id = %d"


#define EDIT_DOCTOR_BY_ID @"UPDATE doctor_tbl SET first_name= \"%@\",last_name= \"%@\", email= \"%@\", address= \"%@\", mobile= \"%@\",phone= \"%@\", date_of_birth= \"%@\" ,updated_time=  \"%@\" WHERE id= %d"

#define EDIT_DOCTOR_BY_UNIQUE_ID @"UPDATE doctor_tbl SET first_name= \"%@\",last_name= \"%@\", email= \"%@\", address= \"%@\", mobile= \"%@\",phone= \"%@\", date_of_birth= \"%@\" ,updated_time=  \"%@\" WHERE uniqueId= \"%@\""

#define GET_DOCTOR_BY_LOGINID @"SELECT * FROM doctor_tbl where login_table_id = %d"

//DOCTOR PRACTICE

#define CREATE_TABLE_DOCTOR_PRACTICE_EXPERIENCE  @"CREATE TABLE if not exists doctor_practice_experience_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT, doctor_id INTEGER, designation STRING, worked_at STRING, from_date STRING, to_date STRING)"

#define SELECT_DOCTOR_PRACTICE_EXPERIENCE_BY_DOCTOR_ID @"SELECT * FROM doctor_practice_experience_tbl WHERE doctor_id = %d"

#define ADD_DOCTOR_PRACTICE_EXPERIENCE @"INSERT INTO doctor_practice_experience_tbl (doctor_id, designation, worked_at, from_date, to_date) VALUES (%d, \"%@\", \"%@\", \"%@\", \"%@\")"

#define DELETE_DOCTOR_PRACTICE_EXPERIENCE_BY_EXPERIENCE_ID @"DELETE FROM doctor_practice_experience_tbl WHERE id = %d"
#define DELETE_case_By_case_ID @"DELETE FROM case_tbl WHERE id = %d"

#define EDIT_DOCTOR_PRACTICE_EXPERIENCE_BY_EXPERIENCE_ID @"UPDATE doctor_practice_experience_tbl SET designation= \"%@\" , worked_at= \"%@\", from_date= \"%@\", to_date= \"%@\" WHERE id=%d"

#define EDIT_CASE_CASE_ID @"UPDATE case_tbl SET case_name= \"%@\" , patient_id=%d,short_desc= \"%@\",long_desc= \"%@\" WHERE id=%d"

//DOCTOR QUALIFICATION

#define CREATE_TABLE_DOCTOR_EDUCATIONAL_QUALIFICATION  @"CREATE TABLE if not exists doctor_educational_qualification_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT, doctor_id INTEGER, educational_degree STRING, passed_out_date STRING, institution STRING)"

#define ADD_DOCTOR_EDUCATIONAL_QUALIFICATION @"INSERT INTO doctor_educational_qualification_tbl (doctor_id, educational_degree, passed_out_date, institution) VALUES (%d, \"%@\", \"%@\", \"%@\")"

#define SELECT_DOCTOR_EDUCATIONAL_QUALIFICATION_BY_DOCTOR_ID @"SELECT * FROM doctor_educational_qualification_tbl WHERE doctor_id = %d"

#define DELETE_DOCTOR_EDUCATIONAL_QUALIFICATION_BY_QUALIFICATION_ID @"DELETE FROM doctor_educational_qualification_tbl WHERE id = %d"

#define EDIT_DOCTOR_EDUCATIONAL_QUALIFICATION_BY_QUALIFICATION_ID @"UPDATE doctor_educational_qualification_tbl SET educational_degree= \"%@\" , passed_out_date= \"%@\", institution= \"%@\" WHERE id=%d"

//DOCTOR ACHIEVEMENT

#define CREATE_TABLE_DOCTOR_ACHIEVEMENT  @"CREATE TABLE if not exists doctor_achievement_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT, doctor_id INTEGER, achievement STRING)"

#define SELECT_DOCTOR_ACHIEVEMENT_BY_DOCTOR_ID @"SELECT * FROM doctor_achievement_tbl WHERE doctor_id = %d"

#define ADD_DOCTOR_ACHIEVEMENT @"INSERT INTO doctor_achievement_tbl (doctor_id, achievement) VALUES (%d, \"%@\")"

#define DELETE_DOCTOR_ACHIEVEMENT_BY_ACHIEVEMENT_ID @"DELETE FROM doctor_achievement_tbl WHERE id = %d"

#define EDIT_DOCTOR_ACHIEVEMENT_BY_ACHIEVEMENT_ID @"UPDATE doctor_achievement_tbl SET achievement= \"%@\" WHERE id=%d"

//DOCTOR EXPERTISE

#define CREATE_TABLE_DOCTOR_EXPERTISE  @"CREATE TABLE if not exists doctor_expertise_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT, doctor_id INTEGER, expertise STRING)"

#define SELECT_DOCTOR_EXPERTISE_BY_DOCTOR_ID @"SELECT * FROM doctor_expertise_tbl WHERE doctor_id = %d"

#define ADD_DOCTOR_EXPERTISE @"INSERT INTO doctor_expertise_tbl (doctor_id, expertise) VALUES (%d, \"%@\")"

#define DELETE_DOCTOR_EXPERTISE_BY_EXPERTISE_ID @"DELETE FROM doctor_expertise_tbl WHERE id = %d"

#define EDIT_DOCTOR_EXPERTISE_BY_EXPERTISE_ID @"UPDATE doctor_expertise_tbl SET expertise = \"%@\" WHERE id = %d"



// DOCTOR MEMBERSHIP

#define CREATE_TABLE_DOCTOR_MEMBERSHIP  "CREATE TABLE if not exists doctor_membership_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT, doctor_id INTEGER, membership STRING)"

#define SELECT_DOCTOR_MEMBERSHIP_BY_DOCTOR_ID @"SELECT * FROM doctor_membership_tbl WHERE doctor_id = %d"

#define ADD_DOCTOR_MEMBERSHIP @"INSERT INTO doctor_membership_tbl (doctor_id, membership) VALUES (%d, \"%@\")"

#define DELETE_DOCTOR_MEMBERSHIP_BY_MEMBERSHIP_ID @"DELETE FROM doctor_membership_tbl WHERE id = %d"

#define EDIT_DOCTOR_MEMBERSHIP_BY_MEMBERSHIP_ID @"UPDATE doctor_membership_tbl SET membership = \"%@\" WHERE id = %d"

#define PRINT_WELCOME_MESSAGE @"SELECT * FROM doctor_tbl WHERE login_table_id=%d"

//  SCHEDULE

#define CREATE_TABLE_DOCTOR_SCHEDULE "CREATE TABLE if not exists doctor_schedule_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT, series_id INTEGER, doctor_id INTEGER, date STRING, starting_time STRING, ending_time STRING, schedule_status STRING, global_id INTEGER, created_time STRING, updated_time STRING, status STRING, uniqueId STRING, FOREIGN KEY(series_id) REFERENCES series_tbl(id))"

#define ADD_SCHEDULE @"INSERT INTO doctor_schedule_tbl (series_id, doctor_id, date, starting_time, ending_time,created_time,updated_time,schedule_status,status,global_id,uniqueId) VALUES (%d, %d,  \"%@\", \"%@\", \"%@\", \"%@\", \"%@\",\"%@\", \"%@\",%d, \"%@\")"

#define CHECK_EXIST_SCHEDULE @"SELECT * FROM doctor_schedule_tbl WHERE starting_time=\"%@\" AND ending_time=\"%@\" AND date=\"%@\""
#define SELECT_ALL_SCHEDULE @"SELECT * FROM doctor_schedule_tbl WHERE status='active'"
#define SELECT_DATE_FROM_SCHEDULE_TABLE @"SELECT date FROM doctor_schedule_tbl WHERE id = (SELECT MAX(id) FROM doctor_schedule_tbl)"
#define UPDATE_ENDDATE_FROM_SERIES_TABLE @"UPDATE series_tbl SET end_date = \"%@\" where id=%d"

#define UPDATE_WEEKLYTYPE_FROM_SERIES_TABLE @"UPDATE series_tbl SET weekly_type = \"%@\"  WHERE id = (SELECT MAX(id) FROM series_tbl)"

//#define SELECT_SCHEDULE_BY_GLOBALID @"SELECT * FROM doctor_schedule_tbl WHERE global_id=0 AND status='active'"

#define SELECT_SCHEDULE_BY_GLOBALID @"SELECT * FROM doctor_schedule_tbl   LEFT OUTER JOIN doctor_tbl   ON doctor_tbl.id=doctor_schedule_tbl.doctor_id WHERE doctor_schedule_tbl.global_id=0 AND doctor_schedule_tbl.status='active'"

#define SELECT_DELETED_SCHEDULE_BY_GLOBALID @"SELECT * FROM doctor_schedule_tbl   LEFT OUTER JOIN doctor_tbl   ON doctor_tbl.id=doctor_schedule_tbl.doctor_id WHERE doctor_schedule_tbl.global_id!=0 AND doctor_schedule_tbl.status='inactive'"

#define SELECT_SERIES_BY_SERIESID @"SELECT * FROM series_tbl WHERE id=%d"



#define UPDATE_SCHEDULE_TABLE_BY_GLOBALID @"UPDATE doctor_schedule_tbl SET global_id=%d WHERE id=%d"

#define UPDATE_SERIES_TABLE_BY_GLOBALID @"UPDATE series_tbl SET global_id=%d WHERE id=%d"
#define DELETE_SERIES_BY_ID @"DELETE FROM series_tbl WHERE global_id = %d"

#define DELETE_SCHEDULE_BY_ID @"DELETE FROM doctor_schedule_tbl WHERE global_id = %d"
#define UPDATE_STATUS_FOR_DELETING_SCHEDULE_BY_ID @"UPDATE doctor_schedule_tbl SET status='inactive' WHERE id = %d"

#define CREATE_TABLE_DOCTOR_MEMBERSHIP  @"CREATE TABLE if not exists doctor_membership_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT, doctor_id INTEGER, membership STRING)"

#define CREATE_TABLE_SERIES @"CREATE TABLE if not exists series_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT, repeat STRING, occurance_type STRING, end_date STRING, weekly_type STRING, ends_on INTEGER, global_id INTEGER)"

#define ADD_SERIES @"INSERT INTO series_tbl (repeat, occurance_type, end_date, weekly_type, ends_on,global_id) VALUES (\"%@\", \"%@\", \"%@\", \"%@\", %d,%d)"

#define SELECT_LAST_SERIESID @"SELECT * FROM series_tbl WHERE id = (SELECT MAX(id) FROM series_tbl)"

#define GET_ALL_SCHEDULES_BY_DOCTOR_ID @"SELECT * FROM doctor_schedule_tbl WHERE doctor_id= %d AND status='active'"
#define GET_ALL_SCHEDULES_BY_DOCTOR_ID_FOR_SCHEDULES @"SELECT * FROM doctor_schedule_tbl LEFT OUTER JOIN series_tbl ON doctor_schedule_tbl.series_id=series_tbl.id WHERE doctor_schedule_tbl.doctor_id=%d AND doctor_schedule_tbl.status='active' AND  series_tbl.end_date>=\"%@\""
#define GET_ALL_SCHEDULES_BY_SERIES_ID @"SELECT * FROM doctor_schedule_tbl WHERE series_id= %d and status='active'"

#define SELECT_SERIES_ID_BY_SCHEDULE_ID @"SELECT series_id FROM doctor_schedule_tbl WHERE id = %d"

//#define DELETE_SCHEDULE_BY_SERIES_ID @"DELETE FROM doctor_schedule_tbl WHERE series_id = %d"
#define UPDATE_STATUS_OF_ALL_SCHEDULE_BY_SERIES_ID @"UPDATE doctor_schedule_tbl SET status='inactive' WHERE series_id = %d"

//#define DELETE_FUTURE_SCHEDULE_BY_SERIES_ID @"DELETE FROM doctor_schedule_tbl WHERE series_id = %d AND id >= %d"
#define UPDATE_STATUS_OF_THIS_FUTURE_SCHEDULE_BY_SERIES_ID @"UPDATE doctor_schedule_tbl SET status='inactive' WHERE series_id = %d AND id >= %d"

// PATIENT

#define CREATE_TABLE_PATIENT @"CREATE TABLE if not exists patient_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT, first_name STRING, last_name STRING, gender STRING, age INTEGER, phone STRING, email STRING, mobile STRING, address STRING, global_id INTEGER,ailment STRING, diagnosis STRING,blood_group STRING,height STRING, weight STRING, chronic_disease STRING, allergies STRING, family_history STRING, emergency_no STRING, status STRING, created_time STRING, updated_time STRING, uniqueId STRING)"

#define INSERT_TABLE_PATIENT @"INSERT INTO patient_tbl (first_name, last_name, gender, age, phone, email, mobile, address,global_id,status,created_time,updated_time,uniqueId) VALUES (\"%@\", \"%@\", \"%@\", %d, \"%@\", \"%@\", \"%@\", \"%@\",%d,\"%@\",\"%@\",\"%@\",\"%@\")"

#define SELECT_ALL_PATIENT @"SELECT * FROM patient_tbl ORDER BY first_name"
#define SELECT_ALL_PATIENT @"SELECT * FROM patient_tbl ORDER BY first_name"

#define SELECT_ALL_PATIENT_BY_GLOBAL_ID @"SELECT * FROM patient_tbl WHERE global_id=0 AND status='active'"

#define SELECT_PATIENT_BY_ID @"SELECT * FROM patient_tbl WHERE id=%d"

#define UPDATE_PATIENT_BY_ID @"UPDATE patient_tbl SET first_name = \"%@\",last_name= \"%@\", gender= \"%@\", age= %d, phone= \"%@\", email= \"%@\", mobile= \"%@\", address = \"%@\", ailment= \"%@\", diagnosis= \"%@\", chronic_disease= \"%@\", allergies= \"%@\", family_history= \"%@\",updated_time=\"%@\"  WHERE id= %d"

#define UPDATE_PATIENT_BY_EMAILID @"UPDATE patient_tbl SET first_name = \"%@\",last_name= \"%@\", gender= \"%@\", age= %d, phone= \"%@\", email= \"%@\", mobile= \"%@\", address = \"%@\", ailment= \"%@\", diagnosis= \"%@\", chronic_disease= \"%@\", allergies= \"%@\", family_history= \"%@\",updated_time=\"%@\" WHERE uniqueId= \"%@\""

#define SELECT_ALL_UPDATED_PATIENT_BY_GLOBALID @"SELECT * FROM patient_tbl LEFT OUTER JOIN sync_tbl WHERE patient_tbl.global_id!=0 AND patient_tbl.created_time!=patient_tbl.updated_time AND patient_tbl.updated_time>sync_tbl.uploaded_time AND patient_tbl.status='active'"

#define UPDATE_PATIENT_TABLE_BY_GLOBALID @"UPDATE patient_tbl SET global_id=%d WHERE id=%d"



#define CREATE_TABLE_CASE @"CREATE TABLE if not exists case_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT, case_name STRING, patient_id INTEGER, short_desc STRING,global_id INTEGER,created_time STRING,updated_time STRING,long_desc STRING, status STRING, date STRING, FOREIGN KEY(patient_id) REFERENCES patient_tbl(id))"

#define SELECT_CASE_BY_PATIENT_ID @"SELECT * FROM case_tbl  WHERE patient_id= %d"

#define SELECT_CASE_BY_CASE_ID @"SELECT * FROM case_tbl  WHERE id= %d"

#define SELECT_CASE_BY_CASE_ID @"SELECT * FROM case_tbl  WHERE id= %d"

#define SELECT_ALL_CASE_BY_GLOBAL_ID @"SELECT * FROM case_tbl  LEFT OUTER JOIN patient_tbl ON case_tbl.patient_id=patient_tbl.id WHERE case_tbl.global_id=0 AND case_tbl.status='active'"


#define INSERT_TABLE_CASE @"INSERT INTO case_tbl (case_name, patient_id, short_desc, long_desc,global_id,created_time ,updated_time,status ) VALUES (\"%@\", %d, \"%@\", \"%@\",%d,\"%@\",\"%@\",\"%@\")"

#define CREATE_TABLE_MEDICAL_RECORD @"CREATE TABLE if not exists medical_record_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT, patient_id INTEGER,global_id INTEGER,medical_record STRING, created_time STRING,updated_time STRING,case_id INTEGER, doctor_id INTEGER, type STRING, date STRING)"

#define INSERT_TABLE_MEDICAL_RECORD @"INSERT INTO medical_record_tbl (patient_id, medical_record, case_id, doctor_id, type,date,global_id,created_time,updated_time,status) VALUES (%d, \"%@\", %d, %d, \"%@\",\"%@\",%d,\"%@\",\"%@\",\"%@\")"

#define SELECT_MEDICAL_RECORD_BY_PATIENT_ID @"SELECT * FROM medical_record_tbl  WHERE patient_id= %d AND type!='visit' "
#define SELECT_MEDICAL_RECORD_BY_CASE_ID @"SELECT * FROM medical_record_tbl  WHERE case_id= %d"

#define DELETE_MEDICAL_RECORD_BY_ID @"DELETE FROM medical_record_tbl WHERE id = %d"

#define EDIT_MEDICAL_RECORD_BY_MEDRECORD_ID @"UPDATE medical_record_tbl SET medical_record= \"%@\",doctor_id = %d,type= \"%@\",date= \"%@\" WHERE id= %d"


#define SELECT_VISIT_BY_PATIENT_ID @"SELECT * FROM medical_record_tbl  WHERE patient_id= %d AND type='visit' "



#define CREATE_TABLE_USER @"CREATE TABLE if not exists user_tbl (id INTEGER PRIMARY KEY, name STRING)"

#define CHECK_PATIENT_EXIST_USING_UNIQUE_ID @"SELECT * FROM patient_tbl WHERE uniqueId = \"%@\""

// APPOINTMENTS

#define CREATE_TABLE_PATIENT_APPOINTMENTS @"CREATE TABLE if not exists patient_appointment_tbl (id INTEGER PRIMARY KEY, patient_id INTEGER, date String, starting_time STRING, doctor_id INTEGER,  schedule_id INTEGER, appointment_status STRING, status STRING, global_id INTEGER, created_time STRING, updated_time STRING)"

#define SELECT_ALL_APPOINTMENT_BY_GLOBAL_ID @"SELECT * FROM patient_appointment_tbl LEFT OUTER JOIN patient_tbl ON patient_appointment_tbl.patient_id=patient_tbl.id  LEFT OUTER JOIN doctor_tbl ON patient_appointment_tbl.doctor_id=doctor_tbl.id  LEFT OUTER JOIN doctor_schedule_tbl  ON patient_appointment_tbl.schedule_id=doctor_schedule_tbl.id WHERE  patient_appointment_tbl.global_id=0 AND patient_appointment_tbl.status='active'"

#define SELECT_ALL_UPDATED_APPOINTMENT_BY_GLOBAL_ID @"SELECT * FROM patient_appointment_tbl LEFT OUTER JOIN patient_tbl ON patient_appointment_tbl.patient_id=patient_tbl.id  LEFT OUTER JOIN doctor_tbl ON patient_appointment_tbl.doctor_id=doctor_tbl.id  LEFT OUTER JOIN doctor_schedule_tbl  ON patient_appointment_tbl.schedule_id=doctor_schedule_tbl.id LEFT OUTER JOIN sync_tbl WHERE  patient_appointment_tbl.global_id!=0 AND patient_appointment_tbl.created_time!=patient_appointment_tbl.updated_time AND patient_appointment_tbl.status='active' AND patient_appointment_tbl.updated_time>sync_tbl.uploaded_time"

#define UPDATE_PATIENT_APPOINTMENT_TABLE_BY_GLOBALID @"UPDATE patient_appointment_tbl SET global_id=%d WHERE id=%d"
//, FOREIGN KEY(patient_id) REFERENCES patient_tbl(id), FOREIGN KEY(doctor_id) REFERENCES doctor_tbl(id), FOREIGN KEY(schedule_id) REFERENCES doctor_schedule_tbl(doctor_schedule_id))

#define INSERT_TABLE_PATIENT_APPOINTMENTS @"INSERT INTO patient_appointment_tbl (patient_id, date, starting_time, doctor_id, schedule_id, appointment_status, status, created_time, updated_time,global_id) VALUES (%d, \"%@\", \"%@\", %d, %d, \"%@\", \"%@\", \"%@\",\"%@\",%d)"

#define SELECT_ALL_APPOINTMENT @"SELECT * FROM patient_appointment_tbl WHERE status='active'"

#define EDIT_APPOINTMENT_BY_ID @"UPDATE patient_appointment_tbl SET patient_id= %d,appointment_status = \"%@\",updated_time= \"%@\" WHERE id= %d"

#define DELETE_APPOINTMENT_BY_GLOBAL_ID @"DELETE FROM patient_appointment_tbl WHERE global_id = %d"

#define DELETE_APPOINTMENT_BY_ID @"UPDATE patient_appointment_tbl SET status='Inactive' WHERE id = %d"
//#define DELETE_APPOINTMENT_BY_ID @"DELETE FROM patient_appointment_tbl  WHERE id = %d"

#define SELECT_ALL_DELETED_APPOINTMENTS_BY_GLOBAL_ID @"SELECT * FROM patient_appointment_tbl LEFT OUTER JOIN patient_tbl ON patient_appointment_tbl.patient_id=patient_tbl.id  LEFT OUTER JOIN doctor_tbl ON patient_appointment_tbl.doctor_id=doctor_tbl.id  LEFT OUTER JOIN doctor_schedule_tbl  ON patient_appointment_tbl.schedule_id=doctor_schedule_tbl.id WHERE  patient_appointment_tbl.global_id!=0 AND patient_appointment_tbl.status!='active'"

#define GET_APPOINTMENT_BY_ID @"SELECT a.id,p.id,p.first_name,p.last_name,d.id,d.first_name,d.last_name,a.created_time FROM patient_appointment_tbl  a LEFT OUTER JOIN patient_tbl  p ON a.patient_id=p.id LEFT OUTER JOIN doctor_tbl  d ON a.doctor_id=d.id WHERE a.id = %d AND a.status='active'"

#define GET_ALL_APPOINTMENTS_BY_DOCTOR_ID @"SELECT * FROM patient_appointment_tbl where doctor_id= %d and status='active'"

#define CREATE_TABLE_LAB @"CREATE TABLE if not exists labs_tbl (lab_id INTEGER PRIMARY KEY, lab_name STRING)"

#define CREATE_TABLE_LAB_BRANCHES "CREATE TABLE if not exists lab_branches_tbl (id INTEGER, branch_id INTEGER, branch_name STRING, lab_id INTEGER, FOREIGN KEY(lab_id) REFERENCES patient_tbl(lab_id))"


//Message
#define CREATE_TABLE_MESSAGE @"CREATE TABLE if not exists message_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT, message STRING, viewed INTEGER, created_time STRING, doctor_id INTEGER, FOREIGN KEY(doctor_id) REFERENCES doctor_tbl (id))"

#define INSERT_TABLE_MESSAGE @"INSERT INTO message_tbl (message, viewed, created_time, doctor_id ) VALUES (\"%@\", %d,\"%@\", %d)"
#define GET_MESSAGE_BY_ID @"SELECT * FROM message_tbl where id= %d"

#define GET_MESSAGES_BY_DOCTOR_ID @"SELECT * FROM message_tbl m LEFT OUTER JOIN doctor_tbl  d ON m.doctor_id=d.id where doctor_id= %d"

#define GET_ALL_MESSAGES @"SELECT * FROM message_tbl m LEFT OUTER JOIN doctor_tbl  d ON m.doctor_id=d.id "

#define EDIT_MESSAGE @"UPDATE message_tbl SET viewed= %d WHERE id= %d"

#define CREATE_TABLE_SYNCMESSAGE @"CREATE TABLE if not exists sync_msg_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT, source STRING, cloudable STRING, create_date STRING, passPhrase STRING, sync_priority STRING,category STRING)"

//UniqueId_tbl

#define CREATE_TABLE_UNIQUE_ID @"CREATE TABLE if not exists uniqueId_tbl (id INTEGER)"

//Doc_schedule_tbl

#define CREATE_TABLE_DOC_SCHEDULE @"CREATE TABLE if not exists doc_schedule_tbl (id INTEGER, startingDate STRING, endingDate STRING)"

#define INSERT_TABLE_DOC_SCHEDULE @"INSERT INTO doc_schedule_tbl (id,startingDate,endingDate) VALUES (%d,\"%@\",\"%@\")"

#define SELECT_ALL_DOC_ID @"SELECT * FROM doc_schedule_tbl"

//timespec_tbl
#define CREATE_TABLE_TIME_SPEC @"CREATE TABLE if not exists timespec_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT, scheduleId INTEGER, facility STRING, timespec STRING)"

#define INSERT_TABLE_TIME_SPEC @"INSERT INTO timespec_tbl (scheduleId,facility,timespec) VALUES (%d,\"%@\",\"%@\")"
#define SELECT_ALL_TIMESPEC @"SELECT * FROM timespec_tbl"
#define SELECT_TIMESPECTBL_ID @"SELECT * FROM timespec_tbl WHERE scheduleId=%d AND timespec= \"%@\""
#define UPDATE_TIMESPEC_BY_ID @"UPDATE timespec_tbl SET timespec = \"%@\" WHERE id= %d"

/*
 //vacation_spec_tbl
 #define CREATE_TABLE_VACATION_SPEC "CREATE TABLE if not exists vacation_spec_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT,startDate STRING,endDate STRING,startTime STRING,endTime STRING,reason STRING,noDays STRING)"
 #define INSERT_TABLE_VACATION_SPEC @"INSERT INTO vacation_spec_tbl (startDate,endDate,startTime,endTime,reason,noDays) VALUES (\"%@\,\"%@\,\"%@\,\"%@\,\"%@\,\"%@\")"
 */

//employee_vaca_tbl
#define CREATE_TABLE_EMPLOYEE_VACATION @"CREATE TABLE if not exists employee_vaca_tbl (id INTEGER PRIMARY KEY AUTOINCREMENT,approvedBy STRING,approvedDate STRING,requestedDate STRING,vacationStatus STRING,emplId INTEGER,reason STRING,timeSpec STRING)"
#define INSERT_TABLE_EMPLOYEE_VACATION @"INSERT INTO employee_vaca_tbl (approvedBy,approvedDate,requestedDate,vacationStatus,emplId,reason,timeSpec) VALUES(\"%@\",\"%@\",\"%@\",\"%@\",%d,\"%@\",\"%@\")"
//unique_tbl
#define INSERT_QUERY @"INSERT INTO uniqueId_tbl (id) VALUES (%d)"

#endif
