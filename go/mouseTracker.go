package main

import "github.com/go-vgo/robotgo"

// MouseTracker will keep track of mouse position
type MouseTracker struct {
	currentX, currentY   int
	previousX, previousY int
}

// Update mouse position information
func (m *MouseTracker) Update() {
	//shift values
	m.previousX = m.currentX
	m.previousY = m.currentY

	//get new values
	m.currentX, m.currentY = robotgo.GetMousePos()
}

// DidMouseMove will detect if the mouse has changed positions
func (m MouseTracker) DidMouseMove() bool {
	return m.previousY != m.currentY || m.previousX != m.currentX
}
