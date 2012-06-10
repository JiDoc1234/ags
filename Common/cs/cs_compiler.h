/*
** 'C'-style script compiler
** Copyright (C) 2000-2001, Chris Jones
** All Rights Reserved.
**
** This is UNPUBLISHED PROPRIETARY SOURCE CODE;
** the contents of this file may not be disclosed to third parties,
** copied or duplicated in any form, in whole or in part, without
** prior express permission from Chris Jones.
**
*/

#ifndef __CS_COMPILER_H
#define __CS_COMPILER_H

// ********* SCRIPT COMPILATION FUNCTIONS **************
// add a script that will be compiled as a header into every compilation
// 'name' is the name of the header, used in error reports
// (only the pointer is stored so don't free the memory)
extern int ccAddDefaultHeader(char *script, char *name);
// don't compile any headers into the compilation
extern void ccRemoveDefaultHeaders(void);

// define a macro which will affect all compilations
void ccDefineMacro(const char *macro, const char *definition);
// clear all predefined macros
void ccClearAllMacros();

// set version for use with #ifversion macros
void ccSetSoftwareVersion(const char *version);

// compile the script supplied, returns NULL on failure
extern ccScript *ccCompileText(const char *script, const char *scriptName);
// write the script to disk (after compiling)
extern void fwrite_script(ccScript *, FILE *);
// free the memory occupied by the script - do NOT attempt to run the
// script after calling this function
extern void ccFreeScript(ccScript *);

#endif // __CS_COMPILER_H