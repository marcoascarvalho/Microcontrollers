/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : usbd_custom_hid_if.c
  * @version        : v2.0_Cube
  * @brief          : USB Device Custom HID interface file.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "usbd_custom_hid_if.h"

/* USER CODE BEGIN INCLUDE */

/* USER CODE END INCLUDE */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
  * @brief Usb device.
  * @{
  */

/** @addtogroup USBD_CUSTOM_HID
  * @{
  */

/** @defgroup USBD_CUSTOM_HID_Private_TypesDefinitions USBD_CUSTOM_HID_Private_TypesDefinitions
  * @brief Private types.
  * @{
  */

/* USER CODE BEGIN PRIVATE_TYPES */

/* USER CODE END PRIVATE_TYPES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Defines USBD_CUSTOM_HID_Private_Defines
  * @brief Private defines.
  * @{
  */

/* USER CODE BEGIN PRIVATE_DEFINES */

/* USER CODE END PRIVATE_DEFINES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Macros USBD_CUSTOM_HID_Private_Macros
  * @brief Private macros.
  * @{
  */

/* USER CODE BEGIN PRIVATE_MACRO */

/* USER CODE END PRIVATE_MACRO */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Variables USBD_CUSTOM_HID_Private_Variables
  * @brief Private variables.
  * @{
  */

/** Usb HID report descriptor. */
__ALIGN_BEGIN static uint8_t CUSTOM_HID_ReportDesc_FS[USBD_CUSTOM_HID_REPORT_DESC_SIZE] __ALIGN_END =
{
		  0x06, 0xFF, 0x00,             /* USAGE_PAGE (Vendor Page: 0xFF00) */
		  0x09, 0x01,                   /* USAGE (Demo Kit) */
		  0xa1, 0x01,                   /* COLLECTION (Application) */
		  /* 6 */

		  /* Led 1 */
		  0x85, LED1_REPORT_ID,         /* REPORT_ID (1) */
		  0x09, 0x01,                   /* USAGE (LED 1) */
		  0x15, 0x00,                   /* LOGICAL_MINIMUM (0) */
		  0x25, 0x01,                   /* LOGICAL_MAXIMUM (1) */
		  0x75, 0x08,                   /* REPORT_SIZE (8) */
		  0x95, LED1_REPORT_COUNT,      /* REPORT_COUNT (1) */
		  0xB1, 0x82,                   /* FEATURE (Data,Var,Abs,Vol) */

		  0x85, LED1_REPORT_ID,         /* REPORT_ID (1) */
		  0x09, 0x01,                   /* USAGE (LED 1) */
		  0x91, 0x82,                   /* OUTPUT (Data,Var,Abs,Vol) */
		  /* 26 */

		  /* Led 2 */
		  0x85, LED2_REPORT_ID,         /* REPORT_ID 2 */
		  0x09, 0x02,                   /* USAGE (LED 2) */
		  0x15, 0x00,                   /* LOGICAL_MINIMUM (0) */
		  0x25, 0x01,                   /* LOGICAL_MAXIMUM (1) */
		  0x75, 0x08,                   /* REPORT_SIZE (8) */
		  0x95, LED2_REPORT_COUNT,      /* REPORT_COUNT (1) */
		  0xB1, 0x82,                   /* FEATURE (Data,Var,Abs,Vol) */

		  0x85, LED2_REPORT_ID,         /* REPORT_ID (2) */
		  0x09, 0x02,                   /* USAGE (LED 2) */
		  0x91, 0x82,                   /* OUTPUT (Data,Var,Abs,Vol) */
		  /* 46 */

		  /* Led 3 */
		  0x85, LED3_REPORT_ID,         /* REPORT_ID (3) */
		  0x09, 0x03,                   /* USAGE (LED 3) */
		  0x15, 0x00,                   /* LOGICAL_MINIMUM (0) */
		  0x25, 0x01,                   /* LOGICAL_MAXIMUM (1) */
		  0x75, 0x08,                   /* REPORT_SIZE (8) */
		  0x95, LED3_REPORT_COUNT,      /* REPORT_COUNT (1) */
		  0xB1, 0x82,                   /* FEATURE (Data,Var,Abs,Vol) */

		  0x85, LED3_REPORT_ID,         /* REPORT_ID (3) */
		  0x09, 0x03,                   /* USAGE (LED 3) */
		  0x91, 0x82,                   /* OUTPUT (Data,Var,Abs,Vol) */
		  /* 66 */

		  /* Led 4 */
		  0x85, LED4_REPORT_ID,         /* REPORT_ID 4) */
		  0x09, 0x04,                   /* USAGE (LED 4) */
		  0x15, 0x00,                   /* LOGICAL_MINIMUM (0) */
		  0x25, 0x01,                   /* LOGICAL_MAXIMUM (1) */
		  0x75, 0x08,                   /* REPORT_SIZE (8) */
		  0x95, LED4_REPORT_COUNT,      /* REPORT_COUNT (1) */
		  0xB1, 0x82,                   /* FEATURE (Data,Var,Abs,Vol) */

		  0x85, LED4_REPORT_ID,         /* REPORT_ID (4) */
		  0x09, 0x04,                   /* USAGE (LED 4) */
		  0x91, 0x82,                   /* OUTPUT (Data,Var,Abs,Vol) */
		  /* 86 */

		  /* key Push Button */
		  0x85, KEY_REPORT_ID,          /* REPORT_ID (5) */
		  0x09, 0x05,                   /* USAGE (Push Button) */
		  0x15, 0x00,                   /* LOGICAL_MINIMUM (0) */
		  0x25, 0x01,                   /* LOGICAL_MAXIMUM (1) */
		  0x75, 0x01,                   /* REPORT_SIZE (1) */
		  0x81, 0x82,                   /* INPUT (Data,Var,Abs,Vol) */

		  0x09, 0x05,                   /* USAGE (Push Button) */
		  0x75, 0x01,                   /* REPORT_SIZE (1) */
		  0xb1, 0x82,                   /* FEATURE (Data,Var,Abs,Vol) */

		  0x75, 0x07,                   /* REPORT_SIZE (7) */
		  0x81, 0x83,                   /* INPUT (Cnst,Var,Abs,Vol) */
		  0x85, KEY_REPORT_ID,          /* REPORT_ID (2) */

		  0x75, 0x07,                   /* REPORT_SIZE (7) */
		  0xb1, 0x83,                   /* FEATURE (Cnst,Var,Abs,Vol) */
		  /* 114 */

		  /* Tamper Push Button */
		  0x85, TAMPER_REPORT_ID,       /* REPORT_ID (6) */
		  0x09, 0x06,                   /* USAGE (Tamper Push Button) */
		  0x15, 0x00,                   /* LOGICAL_MINIMUM (0) */
		  0x25, 0x01,                   /* LOGICAL_MAXIMUM (1) */
		  0x75, 0x01,                   /* REPORT_SIZE (1) */
		  0x81, 0x82,                   /* INPUT (Data,Var,Abs,Vol) */

		  0x09, 0x06,                   /* USAGE (Tamper Push Button) */
		  0x75, 0x01,                   /* REPORT_SIZE (1) */
		  0xb1, 0x82,                   /* FEATURE (Data,Var,Abs,Vol) */

		  0x75, 0x07,                   /* REPORT_SIZE (7) */
		  0x81, 0x83,                   /* INPUT (Cnst,Var,Abs,Vol) */
		  0x85, TAMPER_REPORT_ID,       /* REPORT_ID (6) */

		  0x75, 0x07,                   /* REPORT_SIZE (7) */
		  0xb1, 0x83,                   /* FEATURE (Cnst,Var,Abs,Vol) */
		  /* 142 */

		  /* ADC IN */
		  0x85, ADC_REPORT_ID,          /* REPORT_ID */
		  0x09, 0x07,                   /* USAGE (ADC IN) */
		  0x15, 0x00,                   /* LOGICAL_MINIMUM (0) */
		  0x26, 0xff, 0x00,             /* LOGICAL_MAXIMUM (255) */
		  0x75, 0x08,                   /* REPORT_SIZE (8) */
		  0x81, 0x82,                   /* INPUT (Data,Var,Abs,Vol) */
		  0x85, ADC_REPORT_ID,          /* REPORT_ID (7) */
		  0x09, 0x07,                   /* USAGE (ADC in) */
		  0xb1, 0x82,                   /* FEATURE (Data,Var,Abs,Vol) */
		  /* 161 */

		  0xc0                          /* END_COLLECTION */
};

/* USER CODE BEGIN PRIVATE_VARIABLES */

/* USER CODE END PRIVATE_VARIABLES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Exported_Variables USBD_CUSTOM_HID_Exported_Variables
  * @brief Public variables.
  * @{
  */
extern USBD_HandleTypeDef hUsbDeviceFS;

/* USER CODE BEGIN EXPORTED_VARIABLES */

/* USER CODE END EXPORTED_VARIABLES */
/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_FunctionPrototypes USBD_CUSTOM_HID_Private_FunctionPrototypes
  * @brief Private functions declaration.
  * @{
  */

static int8_t CUSTOM_HID_Init_FS(void);
static int8_t CUSTOM_HID_DeInit_FS(void);
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t event_idx, uint8_t state);

/**
  * @}
  */

USBD_CUSTOM_HID_ItfTypeDef USBD_CustomHID_fops_FS =
{
  CUSTOM_HID_ReportDesc_FS,
  CUSTOM_HID_Init_FS,
  CUSTOM_HID_DeInit_FS,
  CUSTOM_HID_OutEvent_FS
};

/** @defgroup USBD_CUSTOM_HID_Private_Functions USBD_CUSTOM_HID_Private_Functions
  * @brief Private functions.
  * @{
  */

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_Init_FS(void)
{
  /* USER CODE BEGIN 4 */
  return (USBD_OK);
  /* USER CODE END 4 */
}

/**
  * @brief  DeInitializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_DeInit_FS(void)
{
  /* USER CODE BEGIN 5 */
  return (USBD_OK);
  /* USER CODE END 5 */
}

/**
  * @brief  Manage the CUSTOM HID class events
  * @param  event_idx: Event index
  * @param  state: Event state
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t event_idx, uint8_t state)
{
  /* USER CODE BEGIN 6 */
	  switch (event_idx)
	  {
	  case 1:                      /* LED1 */
	    (state == 1) ? HAL_GPIO_WritePin(LED_D1_GPIO_Port, LED_D1_Pin, GPIO_PIN_RESET) : HAL_GPIO_WritePin(LED_D1_GPIO_Port, LED_D1_Pin, GPIO_PIN_SET);
	    break;

	  case 2:                      /* LED2 */
	    (state == 1) ? HAL_GPIO_WritePin(LED_D2_GPIO_Port, LED_D2_Pin, GPIO_PIN_RESET) : HAL_GPIO_WritePin(LED_D2_GPIO_Port, LED_D2_Pin, GPIO_PIN_SET);
	    break;
	  case 3:                      /* LED3 */
	    //(state == 1) ? BSP_LED_On(LED3) : BSP_LED_Off(LED3);
	    break;
	  case 4:                      /* LED4 */
	    //(state == 1) ? BSP_LED_On(LED4) : BSP_LED_Off(LED4);
	    break;

	  default:
		HAL_GPIO_WritePin(LED_D1_GPIO_Port, LED_D1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_D2_GPIO_Port, LED_D2_Pin, GPIO_PIN_RESET);
	    //BSP_LED_Off(LED3);
	    //BSP_LED_Off(LED4);
	    break;
	  }


	return (USBD_OK);
  /* USER CODE END 6 */
}

/* USER CODE BEGIN 7 */
/**
  * @brief  Send the report to the Host
  * @param  report: The report to be sent
  * @param  len: The report length
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
/*
static int8_t USBD_CUSTOM_HID_SendReport_FS(uint8_t *report, uint16_t len)
{
  return USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, report, len);
}
*/
/* USER CODE END 7 */

/* USER CODE BEGIN PRIVATE_FUNCTIONS_IMPLEMENTATION */

/* USER CODE END PRIVATE_FUNCTIONS_IMPLEMENTATION */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

