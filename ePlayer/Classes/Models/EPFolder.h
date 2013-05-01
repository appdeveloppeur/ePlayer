//
//  Folder.h
//  ePlayer
//
//  Created by Eric Huss on 4/10/13.
//  Copyright (c) 2013 Eric Huss. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EPSong.h"
#import "EPCommon.h"

@class EPEntry;

@interface EPFolder : EPEntry <NSCoding, NSCopying>

@property (assign, nonatomic) EPSortOrder sortOrder;
@property (strong, nonatomic) NSMutableArray *entries;
@property (strong, nonatomic) NSUUID *uuid;

+ (EPFolder *)folderWithName:(NSString *)name
                   sortOrder:(EPSortOrder)sortOrder
                 releaseDate:(NSDate *)releaseDate
                     addDate:(NSDate *)addDate
                    playDate:(NSDate *)palyDate;

- (NSString *)sectionTitleForEntry:(EPEntry *)entry;
- (NSArray *)sortedEntries;
- (EPFolder *)folderWithUUID:(NSUUID *)uuid;
- (EPSong *)songWithPersistentID:(NSNumber *)persistentID;

- (void)insertObject:(EPEntry *)value inEntriesAtIndex:(NSUInteger)idx;
//- (void)removeObjectFromEntriesAtIndex:(NSUInteger)idx;
// - (void)insertEntries:(NSArray *)value atIndexes:(NSIndexSet *)indexes;
// - (void)removeEntriesAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInEntriesAtIndex:(NSUInteger)idx withObject:(EPEntry *)value;
// - (void)replaceEntriesAtIndexes:(NSIndexSet *)indexes withEntries:(NSArray *)values;
- (void)addEntriesObject:(EPEntry *)value;
- (void)removeEntriesObject:(EPEntry *)value;
- (void)addEntries:(NSArray *)values;
- (void)removeEntries:(NSArray *)values;
- (void)removeAllEntries;
@end
