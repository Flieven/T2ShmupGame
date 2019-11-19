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
static std::string playerTag = "Player";
static const char* playerSprite = "../Assets/Sprites/SDL_Player.png";
// ===========================

// ===== ENEMY SETTINGS =====
static int enemyWidth = 87;
static int enemyHeight = 23;
static std::string enemyTag = "Enemy";
static const char* enemySprite = "../Assets/Sprites/CampFire.png";
// ===========================

// ===== BACKGROUND SETTINGS =====
static int backgroundWidth = 1920;
static int backgroundHeight = 1080;
static std::string backgroundTag = "Background";
static const char* backgroundSprite = "../Assets/Sprites/yoda.jpg";
// ===========================


// ===== UPGRADE SETTINGS =====
// ============================

// ===== DEBUG SETTINGS =====
static SDL_Color debugColor = { 0, 255, 0, 255 };
// =========================

// ===== MISC SETTINGS =====

// =========================
