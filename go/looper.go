package main

import (
	"context"
	"fmt"
	"time"

	"github.com/go-vgo/robotgo"
)

// InputLooper will press control key every 1 second
type InputLooper struct {
	ctx    context.Context
	cancel context.CancelFunc
}

// NewInputLooper will create a new InputLooper
func NewInputLooper(mainCTX context.Context) *InputLooper {
	ctx, cancel := context.WithCancel(mainCTX)

	go func() {
		for {
			select {
			case <-ctx.Done():
				return
			default:
				fmt.Println("Pressing control")
				robotgo.KeyTap("control")
				time.Sleep(1 * time.Second)
			}
		}
	}()

	return &InputLooper{ctx, cancel}
}

// Stop the InputLooper
func (l InputLooper) Stop() {
	l.cancel()
}
