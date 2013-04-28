//
//  EPLyricView.m
//  ePlayer
//
//  Created by Eric Huss on 4/27/13.
//  Copyright (c) 2013 Eric Huss. All rights reserved.
//

#import "EPLyricView.h"
#import "EPMediaItemWrapper.h"

@implementation EPLyricView

- (void)updateWithSong:(Song *)song
{
    NSMutableString *text = [[NSMutableString alloc] init];
    // Artist
    NSString *artist = song.mediaWrapper.artist;
    NSString *albumArtist = song.mediaWrapper.albumArtist;
    if (artist != nil && albumArtist != nil && ![artist isEqualToString:albumArtist]) {
        [text appendString:[NSString stringWithFormat:@"Artist: %@\n", artist]];
    }
    // Composer
    if (song.mediaWrapper.composer) {
        [text appendString:[NSString stringWithFormat:@"Composer: %@\n", song.mediaWrapper.composer]];
    }
    // Last Play Date
    NSObject *playDate = song.playDate;
    if (playDate == nil) {
        playDate = @"Never";
    }
    [text appendString:[NSString stringWithFormat:@"Last Play Date: %@\n", playDate]];
    // Play Count
    [text appendString:[NSString stringWithFormat:@"Play Count: %@\n", song.playCount]];
    // Added Date
    [text appendString:[NSString stringWithFormat:@"Added To Library: %@\n", song.addDate]];

    [text appendString:@"\n"];
    if (song.mediaWrapper.lyrics) {
        [text appendString:song.mediaWrapper.lyrics];
    }
    self.text = text;
}

@end