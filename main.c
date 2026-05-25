/*!
 * @file        main.c
 *
 * @brief       Main program body
 *
 * @version     V1.0.3
 *
 * @date        2022-12-01
 *
 * @attention
 *
 *  Copyright (C) 2020-2022 Geehy Semiconductor
 *
 *  You may not use this file except in compliance with the
 *  GEEHY COPYRIGHT NOTICE (GEEHY SOFTWARE PACKAGE LICENSE).
 *
 *  The program is only for reference, which is distributed in the hope
 *  that it will be useful and instructional for customers to develop
 *  their software. Unless required by applicable law or agreed to in
 *  writing, the program is distributed on an "AS IS" BASIS, WITHOUT
 *  ANY WARRANTY OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the GEEHY SOFTWARE PACKAGE LICENSE for the governing permissions
 *  and limitations under the License.
 */

/* Includes */
#include "main.h"
#include "oled.h"
/** @addtogroup Examples
  @{
*/


uint8_t temp;
uint8_t txBuffer[50];
uint8_t rxBuffer[10];
uint8_t cord_h,cord_l;//???????
volatile uint32_t nBytesRead = 0;
//volatile bool txThresholdEventReceived = false;
//volatile bool rxThresholdEventReceived = false;

/** @addtogroup USART_Printf
  @{
*/

/** @addtogroup USART_Printf_Variables Variables
  @{
*/

volatile uint32_t tick = 0;
uint8_t txBuf[] = "Key Value = :   \r\n";


/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/**@} end of group USART_Printf_Variables */
void DelayMs(uint16_t nms)
{
	uint16_t i,j;		   
	for(i=0;i<nms;i++)
       for(j=0;j<200;j++); 
} 
/** @addtogroup USART_Printf_Functions Functions
  @{
*/



/*!
 * @brief       Main program
 *
 * @param       None
 *
 * @retval      None
 *
 */
int main(void)
{
    

    GPIO_Config_T GPIO_ConfigStruct;
    USART_Config_T USART_ConfigStruct;

    APM_MINI_LEDInit(LED2);

    RCM_EnableAPB2PeriphClock((RCM_APB2_PERIPH_T)(RCM_APB2_PERIPH_GPIOA | RCM_APB2_PERIPH_USART1));

    GPIO_ConfigStruct.mode = GPIO_MODE_AF_PP;
    GPIO_ConfigStruct.pin = GPIO_PIN_9;
    GPIO_ConfigStruct.speed = GPIO_SPEED_50MHz;
    GPIO_Config(GPIOA, &GPIO_ConfigStruct);

    USART_ConfigStruct.baudRate = 115200;
    USART_ConfigStruct.hardwareFlow = USART_HARDWARE_FLOW_NONE;
    USART_ConfigStruct.mode = USART_MODE_TX;
    USART_ConfigStruct.parity = USART_PARITY_NONE;
    USART_ConfigStruct.stopBits = USART_STOP_BIT_1;
    USART_ConfigStruct.wordLength = USART_WORD_LEN_8B;
    USART_Config(USART1, &USART_ConfigStruct);

    USART_Enable(USART1);

    SysTick_Config(SystemCoreClock / 1000);
		I2C_Init();
		OLED_Init();

   // OLED_ShowChar(0,0,'1',16);

    //OLED_ShowNum(0,2,123,3,16);

    OLED_ShowString(10,0,"21ic",16);

    OLED_ShowCHinese(10,2,0);

                OLED_ShowCHinese(26,2,1);

                OLED_ShowCHinese(42,2,2);

                OLED_ShowCHinese(58,2,3);

                OLED_ShowCHinese(74,2,4);
		
		
    while(1)
    {

			
				

					
    }
}

/*!
 * @brief       Delay
 *
 * @param       None
 *
 * @retval      None
 *
 */
void Delay(void)
{
    tick = 0;

    while(tick < 500);
}

/**@} end of group USART_Printf_Functions */
/**@} end of group USART_Printf */
/**@} end of group Examples */
