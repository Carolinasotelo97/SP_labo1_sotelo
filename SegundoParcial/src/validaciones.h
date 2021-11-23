/*
 * validaciones.h
 *
 *  Created on: 22 nov. 2021
 *      Author: caroo
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_



#endif /* VALIDACIONES_H_ */

/** \brief Asks for a number,validates it and charges it in the pointer to number
 *
 * \param pNumber Pointer to a number
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a non validated number
 * \return 0 if everything's fine or -1 if it's not
 *
 */
int getInt(int* pNumber,char message[],char errorMessage[]);

/** \brief Validates that a string has only numbers
 *
 * \param number The string to validate
 * \return 0 in case the string is only numbers and -1 if it's not
 *
 */
int validatePositiveInteger(char number[]);

/** \brief Asks for a float,validates it and charges it in the pointer to float
 *
 * \param pNumber Pointer to a number
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a non validated float number
 * \return 0 if everything's fine or -1 if it's not
 *
 */
int getFloat(float* pFloat,char message[],char errorMessage[]);

/** \brief Validates that a string has only numbers and one '.'
 *
 * \param numberFloat The string to validate
 * \return 0 in case the string is only numbers or number and one '.' and -1 if it's not
 *
 */
int validatePositiveFloat(char numberFloat[]);

/** \brief Asks for a string and returns it validated
 *
 * \param str The string to write on
  * \param message Message for the user
 * \param errorMessage A message in case the user enters a string that isn't only letters
 *
 */
void getString(char str[],int len,char message[],char errorMessage[]);

/** \brief Validates that a string has only letters
 *
 * \param string The string to validate
 * \return 0 in case the string is only letters and -1 if it's not
 *
 */
int isOnlyLetters(char string[]);

/** \brief asks the user for a character and validates it
 *
 * \param pChar pointer to a character
 * \param message[] A message for the user
 * \param errorMessage[] Message in case the user entered a non valid character
 * \return 0 if everything's fine and -1 if it's not
 *
 */
int getChar(char* pChar,char message[],char errorMessage[]);

/** \brief tells the user to choose between two options and validates it's one of them
 *
 * \param pChar Pointer to the character
 * \param message[] A message for the user
 * \param errorMessage[] Message in case the user entered a non valid character
 * \param option1 char
 * \param option2 char
 * \return 0 if everything's fine and -1 if it's not
 *
 */
int getCharTwoOptions(char* pChar,char message[],char errorMessage[],char option1,char option2);

