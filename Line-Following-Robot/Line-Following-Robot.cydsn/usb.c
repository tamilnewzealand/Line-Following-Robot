/* ========================================
 *
 * Copyright (c) 2017, Alex Andela, Adil Bhayani, Vaishnavi Muppavaram, Sakayan Sitsabesan
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ========================================
*/

#include "usb.h"

/*
 * Initializes the USB UART and sends welcome message.
 */
void init_usb() {
    USBUART_Start(0,USBUART_5V_OPERATION);
    usbPutString("CS301 2017 Group 7\n"); 
}

/*
 * Outputs given string to the USB UART console.
 * 
 * Assumes that *s is a string with allocated space >=64 chars     
 * Since USB implementation retricts data packets to 64 chars, this function truncates the
 * length to 62 char (63rd char is a '!')
 */
void usbPutString(char *s) {
    while (USBUART_CDCIsReady() == 0);
    s[63]='\0';
    s[62]='!';
    USBUART_PutData((uint8*)s,strlen(s));    
}

/*
 * Outputs given char to the USB UART console.
 */
void usbPutChar(char c) {
    while (USBUART_CDCIsReady() == 0);
    USBUART_PutChar(c);
}

/*
 * Outputs given integer to the USB UART console.
 */
void usbPutInt(int value) {
    char buffer_text[BUF_SIZE];
    sprintf(buffer_text,"%d",value);
    usbPutString(buffer_text);
}

/* [] END OF FILE */
