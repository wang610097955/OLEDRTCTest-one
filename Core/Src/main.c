/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "rtc.h"
#include "gpio.h"
#include "stdbool.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void main_menu(void);
void menu_display(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_RTC_Init();
  OLED_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
      main_menu();
      if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_15)==GPIO_PIN_RESET)
      {
       int t = 1;
       while(t<2)
        {
        menu_display();
       if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_10)==GPIO_PIN_RESET)
       {
          t = 2;
       }
       }
       }
  }

      

    /* USER CODE BEGIN 3 */
  /* USER CODE END 3 */
}
void menu_display(void)
{
  HAL_Delay(50);
  OLED_Clear();
  OLED_ShowChinese(0,0,0,16);//中
  OLED_ShowChinese(18,0,1,16);//景
  OLED_ShowChinese(0,18,2,16);//园
  OLED_ShowChinese(18,18,3,16);//电
//  OLED_DrawCircle(60,32,30);
//  OLED_DrawLine(48,16,54,16);
//  OLED_DrawLine(66,16,74,16);
 // OLED_DrawCircle(60,48,5);
 //OLED_DrawPoint(60,40);
  OLED_Refresh();
  
  if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13)==GPIO_PIN_RESET)
  {
    int g = 1;
    int t = 0;
    HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_8);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,GPIO_PIN_SET);
    HAL_Delay(100);
    while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13)==GPIO_PIN_RESET)
    {
      HAL_Delay(100);
      t = t+1;
      if(t==30)
      {
      while(g<2)
      {
      HAL_Delay(50);
      OLED_ShowChinese(92,0,8,16);
      OLED_ShowChinese(108,0,9,16);
      OLED_Refresh();
      HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
      HAL_Delay(500);
      HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET); 
      HAL_Delay(500);
      if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13)==GPIO_PIN_RESET)
      {
        g = 2;
      }
      }
      }
    }
    
  }
  if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_14)==GPIO_PIN_RESET)
  {
    int r = 1;
    int t = 0;
    HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_9);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
    HAL_Delay(100);
    while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_14)==GPIO_PIN_RESET)
    {
      HAL_Delay(100);
      t = t+1;
      if(t==30)
      {
      while(r<2)
      {
      HAL_Delay(50);
      OLED_ShowChinese(92,0,7,16);
      OLED_ShowChinese(108,0,9,16);
      OLED_Refresh();
      HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,GPIO_PIN_SET);
      HAL_Delay(500);
      HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,GPIO_PIN_RESET);
      HAL_Delay(500);
      if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_14)==GPIO_PIN_RESET)
      {
        r = 2;
      }
      }
      }
    }
  }
 
}
void main_menu(void)
{
    RTC_TimeTypeDef stime;
    RTC_DateTypeDef sdate;
   HAL_RTC_GetTime(&hrtc, &stime, RTC_FORMAT_BIN);
   HAL_RTC_GetDate(&hrtc, &sdate, RTC_FORMAT_BIN);
    /* USER CODE END WHILE */
  HAL_Delay(50);
  OLED_Clear();
  OLED_ShowChinese(0,0,0,16);//中
  OLED_ShowChinese(18,0,1,16);//景
  OLED_ShowChinese(36,0,2,16);//园
  OLED_ShowChinese(54,0,3,16);//电
  OLED_ShowChinese(72,0,4,16);//子
  OLED_ShowChinese(90,0,5,16);//科
  OLED_ShowChinese(108,0,6,16);//技
  OLED_ShowString(8,16,"LIAOWANYIYI",16);
  OLED_ShowNum(20,32,2000+sdate.Year,4,16);
  OLED_ShowNum(55,32,sdate.Month,2,16);
  OLED_ShowNum(75,32,sdate.Date,2,16);
  OLED_ShowNum(20,48,stime.Hours,2,16);
  OLED_ShowNum(40,48,stime.Minutes,2,16);
  OLED_ShowNum(60,48,stime.Seconds,2,16);
  OLED_Refresh();
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSEState = RCC_LSE_OFF;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
