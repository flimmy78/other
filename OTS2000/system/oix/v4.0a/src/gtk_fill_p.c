
/*-----------------------------------------------------------------------
	
	Upadate from X11 to GTK ;
	Created by chi.hailong
	Date : 2005.9.20 
	SYC by hcl 2007.12.12
     

---------------------------------------------------------------------*/


#include <gtk/gtk.h> 

#include	"../inc/gtk_ipm_k_def.h"

#include	"../inc/oix.h"
#include	"../inc/gtk_fill_bitmap.h"
#include	"../inc/gtk_widgets.h"



GdkPixmap*	fill_pixmenu[MAX_CRT_NUMBER][MAX_FILL_PATTERN];


unsigned char ipm_bitmaps [MAX_FILL_PATTERN][32] =
{
	 /*  Unfilled  */	
	{	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  },

	/*  Dot 1  */
	{
		0x00, 0x00, 
		0x44, 0x44, 
		0x00, 0x00, 
		0x00, 0x00, 
		0x00, 0x00, 
		0x44, 0x44, 
		0x00, 0x00, 
		0x00, 0x00, 
		0x00, 0x00, 
		0x44, 0x44, 
		0x00, 0x00, 
		0x00, 0x00, 
		0x00, 0x00, 
		0x44, 0x44, 
		0x00, 0x00, 
		0x00, 0x00
		},

	/*  Dots 2  */
	{
		0x00, 0x00, 
		0x64, 0x64, 
		0x46, 0x46, 
		0x00, 0x00, 
		0x00, 0x00, 
		0x64, 0x64, 
		0x46, 0x46, 
		0x00, 0x00, 
		0x00, 0x00, 
		0x64, 0x64, 
		0x46, 0x46, 
		0x00, 0x00, 
		0x00, 0x00, 
		0x64, 0x64, 
		0x46, 0x46, 
		0x00, 0x00
		},

	/*  Slant_Left  */
	{
		0x00, 0x00, 
		0x04, 0x04, 
		0x08, 0x08, 
		0x11, 0x11,	
		0x20, 0x20, 
		0x40, 0x40, 
		0x00, 0x80, 
		0x00, 0x00, 
		0x00, 0x00, 
		0x04, 0x04, 
		0x08, 0x08, 
		0x11, 0x11, 
		0x20, 0x20, 
		0x40, 0x40, 
		0x00, 0x80, 
		0x00, 0x00
	  },

	/* Filled   */
	{	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff  },

	/*  Horizontal  */  
	{
		0x00, 0x00, 
		0x00, 0x00, 
		0x00, 0x00, 
		0xcf, 0xcf,	
		0x00, 0x00, 
		0x00, 0x00, 
		0x00, 0x00, 
		0x30, 0x30, 
		0x00, 0x00, 
		0x00, 0x00, 
		0x00, 0x00, 
		0xfc, 0xfc,	
		0x00, 0x00, 
		0x00, 0x00, 
		0x00, 0x00, 
		0x30, 0x30 
	},

	/*  slant_grid  */
	{
		0x00, 0x00, 
		0x80, 0x80, 
		0x44, 0x44, 
		0x28, 0x28,
		0x10, 0x10, 
		0x28, 0x28, 
		0x04, 0x04, 
		0x02, 0x02,
		0x00, 0x00, 
		0x80, 0x80, 
		0x44, 0x44, 
		0x28, 0x28,
		0x10, 0x10, 
		0x28, 0x28, 
		0x04, 0x04, 
		0x02, 0x02  
	},

	/*  Slant_Right  */
	{
		0x00, 0x80, 
		0x40, 0x40, 
		0x20, 0x20, 
		0x11, 0x11,
		0x08, 0x08, 
		0x04, 0x04, 
		0x00, 0x00, 
		0x00, 0x00, 
		0x00, 0x80, 
		0x40, 0x40, 
		0x20, 0x20, 
		0x11, 0x11, 
		0x08, 0x08, 
		0x04, 0x04, 
		0x00, 0x00, 
		0x00, 0x00
	},

};

 

void	CreateFillPalette (crt_n)
int	crt_n;
{
	int 		i;

	for (i = 0; i < MAX_FILL_PATTERN; i++)
	{
		fill_pixmenu[crt_n][i]	= gdk_bitmap_create_from_data (canvas[crt_n]->window, 
				(const char*)ipm_bitmaps[i], 16, 16);

		if (fill_pixmenu[crt_n][i] == NULL)
		{
			printf("can't create pixmap from %d\n",fill_pixmenu[crt_n][i]);
			exit(1);
		}

	}

}


