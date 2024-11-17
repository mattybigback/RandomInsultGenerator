#ifndef TABLES_HPP
#define TABLES_HPP

// Check for overridden files in CustomInsults first
#if __has_include("CustomInsults/AdjectiveTable.hpp")
#include "CustomInsults/AdjectiveTable.hpp"
#else
#include "AdjectiveTable.hpp"
#endif

#if __has_include("CustomInsults/InsultTable.hpp")
#include "CustomInsults/InsultTable.hpp"
#else
#include "InsultTable.hpp"
#endif

#if __has_include("CustomInsults/ObservationTable.hpp")
#include "CustomInsults/ObservationTable.hpp"
#else
#include "ObservationTable.hpp"
#endif

#if __has_include("CustomInsults/CommandTable.hpp")
#include "CustomInsults/CommandTable.hpp"
#else
#include "CommandTable.hpp"
#endif

#if __has_include("CustomInsults/SplashMessages.hpp")
#include "CustomInsults/SplashMessages.hpp"
#else
#include "SplashMessages.hpp"
#endif

#endif // TABLES_HPP
