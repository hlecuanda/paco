 

#import <Foundation/Foundation.h>

@class PacoExperimentDefinition;
@class PacoExperimentSchedule;
@class PacoModel;
@class PAExperimentDAO;

@interface PacoExperiment : NSObject

@property (nonatomic, copy) PacoExperimentDefinition *definition;
@property (nonatomic, copy) NSString *instanceId;

//the exact time that user joins the experiment

@property (nonatomic,strong) PAExperimentDAO* experimentDao;




@property(nonatomic, retain, readonly) NSDate* joinTime;
@property (nonatomic, assign) long long lastEventQueryTime;
@property (nonatomic, retain) PacoExperimentSchedule *schedule;  // Override schedule from definition.
//@property (retain) PacoExperimentSchedule *overrideSchedule;  // Override schedule from definition.




+ (PacoExperiment*)experimentWithDefinition:(PacoExperimentDefinition*)definition
                                   schedule:(PacoExperimentSchedule*)schedule
                                   joinTime:(NSDate*)joinTime;




+ (PacoExperiment*) experimentWithExperimentDao:(PAExperimentDAO*)definition;



- (id)serializeToJSON;
- (void)deserializeFromJSON:(id)json;

- (BOOL)shouldScheduleNotificationsFromNow;
- (BOOL)shouldScheduleNotificationsFromDate:(NSDate*)fromDate;

- (BOOL)isSelfReportExperiment;
- (BOOL)isScheduledExperiment;

- (BOOL)isExperimentValidSinceDate:(NSDate*)fromDate;

- (BOOL)isFixedLength;
- (BOOL)isOngoing;

//return all esm dates generated and stored for an esm experiment that are later than fromDate,
//if there aren't any esm dates generated yet, return nil
- (NSArray*)ESMSchedulesFromDate:(NSDate*)fromDate;

//The last ESM schedule date generated and stored for an esm experiment
//we use it to determine the next esm cycle start date to generate future esm schedule dates
//if there aren't any esm dates generated yet, return nil
- (NSDate*)lastESMScheduleDate;

- (NSDate*)startDate;
- (NSDate*)endDate;

//return the midnight of joinTime
- (NSDate*)joinDate;

//when definition is refreshed, refresh experiment's schedule
//but keep the esmStartHour, esmEndHour, or times configured specifically by user
//return YES if the schedule is changed, NO if the schedule doesn't need to be updated
- (BOOL)refreshSchedule:(PacoExperimentSchedule*)newSchedule;

- (void)configureSchedule:(PacoExperimentSchedule*)newSchedule;

@end