/*
**************************************************************************
 * Rockchip driver for CIF ISP 1.1
 * (Based on Intel driver for sofiaxxx)
 *
 * Copyright (C) 2015 Intel Mobile Communications GmbH
 * Copyright (C) 2016 Fuzhou Rockchip Electronics Co., Ltd.
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
**************************************************************************
 */

#ifndef _CIF_ISP11_IMG_SRC_H
#define _CIF_ISP11_IMG_SRC_H

struct cif_isp11_img_src;
struct cif_isp11_strm_fmt_desc;
struct cif_isp11_strm_fmt;
struct cif_isp11_csi_config;
enum cif_isp11_pix_fmt;

struct cif_isp11_img_src;
struct pltfrm_soc_cfg;

struct cif_isp11_img_src_ctrl {
	unsigned int id;
	int val;
};

struct cif_isp11_img_src_ext_ctrl {
	int cnt;
	unsigned int class;
	struct cif_isp11_img_src_ctrl *ctrls;
};

struct cif_isp11_img_src *cif_isp11_img_src_to_img_src(
	CIF_ISP11_PLTFRM_DEVICE dev,
	struct pltfrm_soc_cfg *soc_cfg);

int cif_isp11_img_src_s_streaming(
	struct cif_isp11_img_src *img_src,
	bool enable);

int cif_isp11_img_src_s_power(
	struct cif_isp11_img_src *img_src,
	bool on);

int cif_isp11_img_src_enum_strm_fmts(
	struct cif_isp11_img_src *img_src,
	u32 index,
	struct cif_isp11_strm_fmt_desc *strm_fmt_desc);

int cif_isp11_img_src_s_strm_fmt(
	struct cif_isp11_img_src *img_src,
	struct cif_isp11_strm_fmt *strm_fmt);

int cif_isp11_img_src_g_ctrl(
	struct cif_isp11_img_src *img_src,
	int id,
	int *val);

int cif_isp11_img_src_s_ctrl(
	struct cif_isp11_img_src *img_src,
	int id,
	int val);

const char *cif_isp11_img_src_g_name(
	struct cif_isp11_img_src *img_src);

int cif_isp11_img_src_s_ext_ctrls(
	struct cif_isp11_img_src *img_src,
	struct cif_isp11_img_src_ext_ctrl *ctrls);

long cif_isp11_img_src_ioctl(
	struct cif_isp11_img_src *img_src,
	unsigned int cmd,
	void *arg);

#endif
