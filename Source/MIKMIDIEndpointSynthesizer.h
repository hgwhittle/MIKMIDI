//
//  MIKMIDIEndpointSynthesizer.h
//  MIKMIDI
//
//  Created by Andrew Madsen on 5/27/14.
//  Copyright (c) 2014 Mixed In Key. All rights reserved.
//

#import "MIKMIDISynthesizer.h"

@class MIKMIDIEndpoint;
@class MIKMIDISourceEndpoint;
@class MIKMIDIClientDestinationEndpoint;
@class MIKMIDISynthesizerInstrument;

/**
 *  MIKMIDIEndpointSynthesizer provides a very simple way to synthesize MIDI commands coming from a
 *  source endpoint (e.g. from a connected MIDI piano keyboard) to produce sound output.
 *
 *  To use it, simply create a synthesizer instance with the source you'd like it to play. It will
 *  continue playing incoming MIDI until it is deallocated.
 */
@interface MIKMIDIEndpointSynthesizer : MIKMIDISynthesizer

/**
 *  Creates and initializes an MIKMIDIEndpointSynthesizer instance using Apple's DLS synth as the
 *  underlying instrument.
 *
 *  @param source An MIKMIDISourceEndpoint instance from which MIDI note events will be received.
 *
 *  @return An initialized MIKMIDIEndpointSynthesizer or nil if an error occurs.
 */
+ (instancetype)playerWithMIDISource:(MIKMIDISourceEndpoint *)source;

/**
 *  Creates and initializes an MIKMIDIEndpointSynthesizer instance.
 *
 *  @param source An MIKMIDISourceEndpoint instance from which MIDI note events will be received.
 *
 *  @param componentDescription an AudioComponentDescription describing the Audio Unit instrument
 *  you would like the synthesizer to use.
 *
 *  @return An initialized MIKMIDIEndpointSynthesizer or nil if an error occurs.
 */
+ (instancetype)playerWithMIDISource:(MIKMIDISourceEndpoint *)source componentDescription:(AudioComponentDescription)componentDescription;

/**
 *  Initializes an MIKMIDIEndpointSynthesizer instance using Apple's DLS synth as the
 *  underlying instrument.
 *
 *  @param source An MIKMIDISourceEndpoint instance from which MIDI note events will be received.
 *
 *  @return An initialized MIKMIDIEndpointSynthesizer or nil if an error occurs.
 */
- (instancetype)initWithMIDISource:(MIKMIDISourceEndpoint *)source;

/**
 *  Initializes an MIKMIDIEndpointSynthesizer instance.
 *
 *  @param source An MIKMIDISourceEndpoint instance from which MIDI note events will be received.
 *
 *  @param componentDescription an AudioComponentDescription describing the Audio Unit instrument
 *  you would like the synthesizer to use.
 *
 *  @return An initialized MIKMIDIEndpointSynthesizer or nil if an error occurs.
 */
- (instancetype)initWithMIDISource:(MIKMIDISourceEndpoint *)source componentDescription:(AudioComponentDescription)componentDescription;

/**
 *  Creates and initializes an MIKMIDIEndpointSynthesizer instance using Apple's DLS synth as the
 *  underlying instrument.
 *
 *  @param destination An MIKMIDIClientDestinationEndpoint instance from which MIDI note events will be received.
 *
 *  @return An initialized MIKMIDIEndpointSynthesizer or nil if an error occurs.
 */
+ (instancetype)synthesizerWithClientDestinationEndpoint:(MIKMIDIClientDestinationEndpoint *)destination;

/**
 *  Creates and initializes an MIKMIDIEndpointSynthesizer instance.
 *
 *  @param destination An MIKMIDIClientDestinationEndpoint instance from which MIDI note events will be received.
 *
 *  @param componentDescription an AudioComponentDescription describing the Audio Unit instrument
 *  you would like the synthesizer to use.
 *
 *  @return An initialized MIKMIDIEndpointSynthesizer or nil if an error occurs.
 */
+ (instancetype)synthesizerWithClientDestinationEndpoint:(MIKMIDIClientDestinationEndpoint *)destination componentDescription:(AudioComponentDescription)componentDescription;

/**
 *  Initializes an MIKMIDIEndpointSynthesizer instance using Apple's DLS synth as the
 *  underlying instrument.
 *
 *  @param destination An MIKMIDIClientDestinationEndpoint instance from which MIDI note events will be received.
 *
 *  @return An initialized MIKMIDIEndpointSynthesizer or nil if an error occurs.
 */
- (instancetype)initWithClientDestinationEndpoint:(MIKMIDIClientDestinationEndpoint *)destination;

/**
 *  Initializes an MIKMIDIEndpointSynthesizer instance.
 *
 *  @param destination An MIKMIDIClientDestinationEndpoint instance from which MIDI note events will be received.
 *
 *  @param componentDescription an AudioComponentDescription describing the Audio Unit instrument
 *  you would like the synthesizer to use.
 *
 *  @return An initialized MIKMIDIEndpointSynthesizer or nil if an error occurs.
 */
- (instancetype)initWithClientDestinationEndpoint:(MIKMIDIClientDestinationEndpoint *)destination componentDescription:(AudioComponentDescription)componentDescription;

// Properties

/**
 *  The endpoint from which the receiver is receiving MIDI messages.
 *  This may be either an external MIKMIDISourceEndpoint, e.g. to synthesize MIDI
 *  events coming from an external MIDI keyboard, or it may be an MIKMIDIClientDestinationEndpoint,
 *  e.g. to synthesize MIDI events coming from an another application on the system.
 */
@property (nonatomic, strong, readonly) MIKMIDIEndpoint *endpoint;

@end

