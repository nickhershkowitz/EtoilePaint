/** <title>ETBezierHandle</title>
	
	<abstract>ETHandle related classes for manipulating a NSBezierPath</abstract>

	Copyright (C) 2009 Eric Wasylishen

	Author:  Eric Wasylishen <ewasylishen@gmail.com>
	Date: August 2009
	License:  Modified BSD (see COPYING)
 */

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import <EtoileUI/ETHandle.h>
#import <EtoileUI/ETLayoutItem.h>
#import <EtoileUI/ETLayoutItemGroup.h>
#import <EtoileUI/ETActionHandler.h>
#import <EtoileUI/ETStyle.h>

#import "NSBezierPath+Editing.h"

@class ETTool; 

@interface ETBezierHandle : ETHandle
{
    ETBezierPathPartcode _partcode;
}

- (id) initWithActionHandler: (ETActionHandler *)anHandler
           manipulatedObject: (id)aTarget
                    partcode: (ETBezierPathPartcode)partcode
          objectGraphContext: (COObjectGraphContext *)aContext;

- (NSBezierPath *) manipulatedPath;
- (ETBezierPathPartcode) partcode;

@end

// Should be a subclass of ETHandleGroup
@interface ETBezierHandleGroup : ETLayoutItemGroup
{
}

- (id) initWithManipulatedObject: (id)aTarget
              objectGraphContext: (COObjectGraphContext *)aContext;
- (id) initWithActionHandler: (ETActionHandler *)anHandler
           manipulatedObject: (id)aTarget
          objectGraphContext: (COObjectGraphContext *)aContext;
- (void) updateHandleLocations;

- (id) manipulatedObject;
- (NSBezierPath *) manipulatedPath;

- (void) setManipulatedObject: (id)anObject;
- (void) setNeedsDisplay: (BOOL)flag;
- (BOOL) acceptsActionsForItemsOutsideOfFrame;

@end

/* Action and Style Aspects */

@interface ETBezierPointActionHandler : ETHandleActionHandler
- (void) handleTranslateItem: (ETHandle *)handle byDelta: (NSSize)delta;
@end

@interface ETBezierControlPointActionHandler : ETHandleActionHandler
- (void) handleTranslateItem: (ETHandle *)handle byDelta: (NSSize)delta;
@end

@interface ETBezierPointStyle : ETBasicHandleStyle
- (void) drawHandleInRect: (NSRect)rect;
@end

@interface ETBezierControlPointStyle : ETBasicHandleStyle
- (void) drawHandleInRect: (NSRect)rect;
@end

