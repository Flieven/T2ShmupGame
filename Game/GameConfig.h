#pragma once

#include <string>
#include <SDL.h>

/*
USE THIS .h FILE TO CREATE STATIC VARIABLES USED IN OTHER AREAS OF CODE.
ESSENTIALLY ALL FILEPATHS IN ASSETS, WINDOW SIZES, PLAYER SIZE, ETC.
*/

// ===== WINDOW SETTINGS =====
static const char* windowTitle = "ShmupGame";
static int windowWidth = 640;
static int windowHeight = 480;

static SDL_Color backgroundColor = { 30, 30, 60, 255 };
// ===========================

// ===== PLAYER SETTINGS =====
static int playerWidth = 20;
static int playerHeight = 20;
// ===========================

// ===== ENEMY SETTINGS =====
// ===========================

// ===== UPGRADE SETTINGS =====
// ============================

// ===== MISC SETTINGS =====
// =========================
