/**
 * @file    TEMPLATE.h
 * @author  Simone Ruffini [simone.ruffini@squadracorsepolito.com | simone.ruffini.work@gmail.com]
 * @date    Mon Jul  8 11:54:13 PM CEST 2024
 * @updated Mon Jul  8 11:54:13 PM CEST 2024
 * @version v0.0.0
 * @prefix  PCA9555
 *
 * @brief   Implementation of PCA9555 IO Multiplexer driver
 *
 * @license Licensed under "THE BEER-WARE LICENSE", Revision 69 
 *          see LICENSE file in the root directory of this software component
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _PCA9555_H_
#define _PCA9555_H_

/* ---------- Includes ------------------------------------------------------*/
#include "i2c.h"

/* ---------- Exported types ------------------------------------------------*/

enum PCA9555_PinPolarity { PCA9555_POLARITY_NORMAL, PCA9555_POLARITY_INVERTED };

enum PCA9555_PinMode { PCA9555_PIN_OUTPUT_MODE, PCA9555_PIN_INPUT_MODE };

enum PCA9555_BitValue { PCA9555_BIT_RESET, PCA9555_BIT_SET };

/* pca9555 struct type for multi-instances handling */
struct PCA9555_Handle {
    I2C_HandleTypeDef *hi2c;
    uint16_t addr;
};

/* ---------- Exported constants --------------------------------------------*/

// Addresses (A0-A2)
#define PCA9555_ADDR_FIXED_PART      (0b0100000U)
#define PCA9555_ADDR_FIXED_PART_MASK (0b0000111U)
#define PCA9555_ADDR_20              0x20
#define PCA9555_ADDR_21              0x21
#define PCA9555_ADDR_22              0x22
#define PCA9555_ADDR_23              0x23
#define PCA9555_ADDR_24              0x24
#define PCA9555_ADDR_25              0x25
#define PCA9555_ADDR_26              0x26
#define PCA9555_ADDR_27              0x27

/* Command Bytes */
#define PCA9555_CB_INPUTS_PORTS     0x00
#define PCA9555_CB_OUTPUTS_PORTS    0x02
#define PCA9555_CB_POL_INVERT_PORTS 0x04
#define PCA9555_CB_CONFIG_PORTS     0x06

/* ---------- Exported variables --------------------------------------------*/

/* ---------- Exported macros -----------------------------------------------*/

/* ---------- Exported functions --------------------------------------------*/

HAL_StatusTypeDef PCA9555_init(struct PCA9555_Handle *hdev, I2C_HandleTypeDef *hi2c, uint16_t addr);
HAL_StatusTypeDef PCA9555_digitalWrite(struct PCA9555_Handle *hdev, uint8_t pin, GPIO_PinState pinState);
HAL_StatusTypeDef PCA9555_digitalRead(struct PCA9555_Handle *hdev, uint8_t pin, uint8_t *data);
HAL_StatusTypeDef PCA9555_pinMode(struct PCA9555_Handle *hdev,
                                  uint8_t pin,
                                  enum PCA9555_PinMode mode,
                                  enum PCA9555_PinPolarity polarity);

/* ---------- Private types -------------------------------------------------*/

/* ---------- Private variables ---------------------------------------------*/

/* ---------- Private constants ---------------------------------------------*/

/* ---------- Private Macros ------------------------------------------------*/

#endif
