#pragma once

#include <SDL.h>

/*
USE THIS .h FILE TO CREATE STATIC VARIABLES USED IN OTHER AREAS OF CODE.
ESSENTIALLY ALL FILEPATHS IN ASSETS, WINDOW SIZES, PLAYER SIZE, ETC.
*/

// ===== WINDOW SETTINGS =====
static const char* windowTitle = "ShmupGame";
static int windowWidth = 1920;
static int windowHeight = 1080;

static SDL_Color backgroundColor = { 30, 30, 60, 255 };
// ===========================

// ===== PLAYER SETTINGS =====
static int playerWidth = 25;
static int playerHeight = 60;
static const char* playerSprite = "../Assets/Sprites/SDL_Player.png";
// ===========================

// ===== ENEMY SETTINGS =====
static int enemyWidth = 87;
static int enemyHeight = 23;
static const char* enemySprite = "../Assets/Sprites/CampFire.png";
// ===========================

// ===== CLOUD SETTINGS =====
static int cloudWidth = 32;
static int cloudHeight = 8;
static const char* cloudSprite = "../Assets/Sprites/Cloud.png";
// ===========================

// ===== UPGRADE SETTINGS =====
// ============================

// ===== MISC SETTINGS =====
// =========================
