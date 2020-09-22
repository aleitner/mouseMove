package main

import (
	"context"
	"fmt"
	"time"
)

func main() {

	ctx := context.Background()

	// create looper and mouse tracker
	looper := NewInputLooper(ctx)
	mt := &MouseTracker{}

	for {
		// update mouseMeta
		mt.Update()

		// determine if mouse moved
		if mt.DidMouseMove() {
			looper.Stop()
			fmt.Println("Paused...")
			time.Sleep(5 * time.Minute)
			looper = NewInputLooper(ctx)
		}
	}

	// kill the looper
	looper.Stop()
}
