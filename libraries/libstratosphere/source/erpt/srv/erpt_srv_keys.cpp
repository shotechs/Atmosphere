/*
 * Copyright (c) Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stratosphere.hpp>
#include "erpt_srv_keys.hpp"

namespace ams::erpt::srv {

    namespace {

        constexpr const u8 PublicKeyModulusProduction[] = {
            0x00,
            0xAB, 0xB6, 0x6C, 0x43, 0x86, 0xDF, 0x52, 0x5F, 0xB9, 0xD3, 0x61, 0xEB, 0xFB, 0x16, 0x2B, 0x44,
            0xE1, 0x1F, 0xDD, 0x81, 0xFA, 0x20, 0x48, 0x7B, 0xDB, 0x17, 0x9F, 0x9A, 0x92, 0x1E, 0x0A, 0x80,
            0xD1, 0x1A, 0x4F, 0xD7, 0x49, 0xFE, 0xBA, 0x65, 0xE4, 0x61, 0x08, 0x26, 0x43, 0x7B, 0x4A, 0x16,
            0x59, 0x60, 0xD1, 0xE0, 0x42, 0x0A, 0x26, 0x54, 0xC4, 0xC7, 0x2A, 0xE3, 0x17, 0x1F, 0x8E, 0x35,
            0x79, 0xC0, 0x1B, 0xA1, 0xF8, 0x6F, 0x5C, 0xDC, 0x05, 0x2D, 0x90, 0x75, 0xD5, 0x98, 0x7E, 0x5A,
            0x07, 0x3F, 0x4E, 0x78, 0xF1, 0x69, 0x2F, 0xE9, 0x2E, 0x50, 0x01, 0x9F, 0xCE, 0x35, 0xC8, 0x4D,
            0x65, 0x23, 0xA8, 0x9F, 0xC3, 0x3C, 0x4A, 0xF2, 0x29, 0x4D, 0x10, 0x03, 0x1C, 0xB4, 0x0E, 0x64,
            0xB6, 0xDD, 0xB2, 0x74, 0xE3, 0x32, 0x84, 0x25, 0x99, 0xEA, 0xE1, 0x6C, 0x78, 0x24, 0xF2, 0xB0,
            0xD2, 0x2C, 0xA5, 0x1A, 0x70, 0xA6, 0x49, 0x08, 0x73, 0x8A, 0x74, 0x3A, 0x12, 0x0E, 0x1B, 0x68,
            0xD1, 0x6A, 0x6C, 0x3F, 0x2C, 0x2C, 0x53, 0xD5, 0xCE, 0x5A, 0x07, 0xA2, 0xB9, 0x2E, 0x0A, 0x77,
            0x51, 0x4B, 0xD2, 0x8E, 0x4F, 0xA3, 0xA8, 0x56, 0x99, 0x6F, 0x63, 0xBC, 0x23, 0x04, 0x6E, 0x71,
            0x57, 0x7C, 0xFD, 0x84, 0xA7, 0xF8, 0x8D, 0x7F, 0xD6, 0xA0, 0x6E, 0x92, 0xBC, 0xCC, 0x28, 0x82,
            0x60, 0xE9, 0x78, 0xC1, 0x31, 0x82, 0x4F, 0xF8, 0xC5, 0xDB, 0xB6, 0x6B, 0xF9, 0x62, 0x95, 0xD3,
            0xC8, 0x63, 0x59, 0x53, 0x3F, 0x82, 0xEB, 0x06, 0xA7, 0xB8, 0x55, 0xEC, 0x9E, 0x33, 0x04, 0xCF,
            0x5E, 0x42, 0x32, 0x09, 0x26, 0xFF, 0xB4, 0x5E, 0xBD, 0xD7, 0xA8, 0x6B, 0x2C, 0xF5, 0x68, 0x86,
            0xCD, 0x8A, 0x13, 0xF3, 0x1C, 0x5F, 0xE6, 0x4F, 0xFC, 0xD1, 0x07, 0x28, 0x5C, 0x2D, 0xA7, 0xF7
        };

        constexpr const u8 PublicKeyModulusDevelopment[] = {
            0x00,
            0xAE, 0x7D, 0x6C, 0xD0, 0xC3, 0x13, 0x61, 0x01, 0x9D, 0x1B, 0x55, 0xA0, 0xE5, 0xF4, 0x3D, 0x56,
            0x7D, 0xCA, 0x0E, 0x49, 0xFB, 0x82, 0x08, 0x06, 0x33, 0xB6, 0x37, 0xB3, 0x4A, 0x3F, 0x57, 0x39,
            0x05, 0x84, 0x18, 0x3D, 0x82, 0xD8, 0x8F, 0xBC, 0xF3, 0xE1, 0x66, 0xEE, 0xD2, 0x80, 0x43, 0xF8,
            0xA7, 0xB7, 0x5E, 0x5B, 0x5C, 0xF9, 0x9D, 0x7F, 0xE9, 0x6C, 0x93, 0x8A, 0x65, 0xBB, 0xD1, 0xDD,
            0x56, 0xFF, 0x7C, 0x9D, 0x24, 0x66, 0x09, 0x84, 0x21, 0x2C, 0x7F, 0x0A, 0xB8, 0x31, 0x42, 0x29,
            0xE6, 0xD3, 0x20, 0x76, 0xA1, 0x1F, 0x7E, 0x59, 0x5B, 0x7C, 0xF6, 0xC6, 0x02, 0xDB, 0xC9, 0x1B,
            0xB9, 0x24, 0x99, 0xAD, 0x0F, 0x7B, 0x0D, 0x8E, 0x7E, 0x01, 0xFE, 0x95, 0xCE, 0x9B, 0xB5, 0x09,
            0xC5, 0xF5, 0xA5, 0x6A, 0x82, 0xF6, 0x57, 0xF8, 0x06, 0x72, 0xAE, 0x73, 0x71, 0xD1, 0x09, 0x2B,
            0xE2, 0x84, 0x0D, 0x66, 0x39, 0xB6, 0x21, 0x8B, 0x35, 0xE4, 0xDF, 0x90, 0x36, 0xE1, 0x3F, 0xC0,
            0x9F, 0xF8, 0x85, 0x03, 0xD6, 0xCA, 0xBB, 0x1A, 0x62, 0x2D, 0xE5, 0x03, 0xF6, 0x47, 0x00, 0x6E,
            0x98, 0x5A, 0x1C, 0x51, 0x94, 0x47, 0xF6, 0x83, 0x0C, 0x25, 0xBD, 0xBE, 0xBD, 0x6A, 0x35, 0xC0,
            0xAB, 0x65, 0xF8, 0x01, 0xF4, 0xC3, 0x2A, 0xA3, 0xBC, 0xD7, 0xD9, 0xF7, 0x2A, 0x98, 0x27, 0xE1,
            0x3F, 0x9A, 0xCF, 0xDF, 0xB1, 0x30, 0x82, 0xA4, 0xAA, 0x78, 0xCA, 0xC8, 0xB8, 0x34, 0xFA, 0xA7,
            0x75, 0x23, 0xC9, 0x9C, 0x11, 0x68, 0x7E, 0x0F, 0x80, 0x8F, 0x90, 0xA6, 0xDE, 0x2B, 0x47, 0x5B,
            0x94, 0x6F, 0xB9, 0x67, 0x4C, 0xC1, 0xAE, 0x50, 0x8F, 0xD8, 0xE3, 0xD1, 0xF2, 0x92, 0x54, 0x4C,
            0x25, 0x02, 0x5B, 0x31, 0x65, 0x5E, 0x41, 0x81, 0x34, 0xF4, 0xF1, 0x34, 0xE7, 0x64, 0x7A, 0xC1
        };

        constexpr const u8 PublicKeyExponent[] = {
            0x01, 0x00, 0x01
        };

        bool IsProductionModeImpl() {
            bool is_prod = true;
            if (settings::fwdbg::GetSettingsItemValue(std::addressof(is_prod), sizeof(is_prod), "erpt", "production_mode") != sizeof(is_prod)) {
                return true;
            }
            return is_prod;
        }

        bool IsProductionMode() {
            static constinit bool s_initialized  = false;
            static constinit bool s_is_prod_mode = true;
            static constinit os::SdkMutex s_mutex;

            if (AMS_UNLIKELY(!s_initialized)) {
                std::scoped_lock lk(s_mutex);

                if (AMS_LIKELY(!s_initialized)) {
                    s_is_prod_mode = IsProductionModeImpl();
                    s_initialized = true;
                }
            }

            return s_is_prod_mode;
        }

    }

    const u8 *GetPublicKeyModulus() {
        return IsProductionMode() ? PublicKeyModulusProduction : PublicKeyModulusDevelopment;
    }

    size_t GetPublicKeyModulusSize() {
        return IsProductionMode() ? sizeof(PublicKeyModulusProduction) : sizeof(PublicKeyModulusDevelopment);
    }

    const u8 *GetPublicKeyExponent() {
        return PublicKeyExponent;
    }

    size_t GetPublicKeyExponentSize() {
        return sizeof(PublicKeyExponent);
    }

}
