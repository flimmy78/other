/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
//#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "gtk_menu.h"
#include "/home/ems/system/oix/v4.0a/inc/oix.h"

extern char*	_toUtf8(char *c);
extern char*	_toUtf8EX(char *c);
int		getMenuDataPointer(int crtn,int data);

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  gtk_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GtkDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  gtk_object_set_data (G_OBJECT (component), name, widget)
  
#define STR_TO_UTF8(string) \
	_toUtf8EX(string)
//		g_locale_to_utf8(_CS_((string)),-1,NULL,NULL,NULL)
		
   extern  DEMO_DSP_CLASS demo_dsp_class[10];  
    
GtkWidget*
create_main_menu (gint crt_n)
{
 int i;
  GtkWidget *menubar1;
  GtkWidget *menuitem1;
  GtkWidget *menuitem1_menu;
  GtkWidget *item11;
  GtkWidget *image67;
  GtkWidget *item12;
  GtkWidget *image68;
  GtkWidget *item13;
  GtkWidget *item14;
  GtkWidget *separatormenuitem1;
  GtkWidget *_______q_1;
  GtkWidget *menuitem2;
  GtkWidget *menuitem2_menu;
  GtkWidget *item21;
  GtkWidget *image69;
  GtkWidget *item101;
  GtkWidget *item22;
  GtkWidget *item23;

  GtkWidget *item24;
  GtkWidget *item25;
  GtkWidget *item80;
  GtkWidget *item80_menu;

  GtkWidget *item800;
  GtkWidget *item801;
  GtkWidget *item802;
  GtkWidget *item803;
  GtkWidget *item804;

  GtkWidget *item26  ,*item27;
  GtkWidget *image_______q_1;
 
  GtkWidget *menuitem3;
  GtkWidget *menuitem3_menu;
  GtkWidget *item31;
  GtkWidget *item32;
//  GtkWidget *_________2;
  GtkWidget *real_time1;
  GtkWidget *real_time1_menu;
  GtkWidget *item41,*turn[MAX_DEMO_DSP_NUM],*auto_disp_menu;
  GtkWidget *item42;
 GtkWidget *item43,*item44,*item45,*item46;
 
  GtkWidget *______1;
  GtkWidget *______1_menu;
  GtkWidget *item51;
  GtkWidget *item511;
  GtkWidget *image70;
  GtkWidget *item52;
  GtkWidget *item53;

  GtkWidget *item54;
  GtkWidget *item550;
  GtkWidget *item55;
	GtkWidget *item56;
  GtkWidget *option;
  GtkWidget *image71;
  GtkWidget *option_menu;
  GtkWidget *item61;
  GtkWidget *item62;
//#ifdef SUN_OS
  GtkWidget *item63;
  GtkWidget *del_menu;
  GtkWidget *sftcp;
  GtkWidget *sgzy;
  GtkWidget *item33;
  GtkWidget *item57;
  GtkWidget *_________7;
  GtkWidget *timer_label;
//#endif
  GtkWidget *item64;
  GtkWidget *image72;

  GtkWidget *item65;

  GtkWidget *item66 ;

  GtkWidget	*itemOperatingCurve;	//zlb  运行特性曲线
  GtkWidget	*itemGenPowerPlanCurve;	//zlb 发电计划曲线

  GtkWidget *item70;
	GtkWidget *item67, *item68,*item69;
  GtkWidget *item102;  
  GtkWidget *image73;
   GSList *group ;
  GtkWidget *image74;   
  GtkWidget *menuitemRpt;
  GtkWidget *menuitemRpt_menu;
  GtkWidget *_______rpt_cur_day;
  GtkWidget *_______rpt_cur_mon;
  GtkWidget *_______rpt_hist;
  GtkWidget *menuitem4;
  GtkWidget *menuitem4_menu,*itemDispEntry;

  GtkWidget *menuitem5;
  GtkWidget *menuitem5_menu;
  GtkWidget *item_simu_main;
  GtkWidget *item_simu_settask;
  GtkWidget *item_simu_setscene;
  GtkWidget *item_simu_setfault;
  GtkWidget *item_simu_currenttask;
  GtkWidget *item_simu_revert;
  GtkWidget *item_simu_local_opr;
  GtkWidget *item_simu_history;
  GtkWidget *item_simu_sendmsg;
  GtkWidget *item_simu_exam;

  GtkWidget *itemcheck_a; //巡检
  GtkWidget *opencheck; //巡检
  GtkWidget *itemcheck_a_menu;
  GtkWidget *itemcheck_b;//条件巡检
  
  GtkWidget *itemcheck_a01;
//  GtkWidget *itemcheck_a02;

  GtkWidget *_______a_1;
  GtkAccelGroup *accel_group;
   GtkWidget*datamenu ; GtkWidget*data_menu;
   GSList *rpt_group=NULL; 
   int MenuPointer;

   gchar *pConvert=0;

   int stn_num;
  accel_group = gtk_accel_group_new ();
  menubar1 = gtk_menu_bar_new ();
  gtk_widget_show (menubar1);
  

  menuitem1 = gtk_menu_item_new_with_mnemonic ( _(STR_TO_UTF8( STR_REGISTER )));
  gtk_widget_show (menuitem1);
  gtk_container_add (GTK_CONTAINER (menubar1), menuitem1);
  

  menuitem1_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem1), menuitem1_menu);

  item11 = gtk_image_menu_item_new_with_label(STR_TO_UTF8(STR_REGISTER_IN)) ;
  gtk_widget_show (item11);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), item11);

  image67 = gtk_image_new_from_stock ("gnome-stock-about", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image67);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item11), image67);

  item12 = gtk_image_menu_item_new_with_label ( STR_TO_UTF8( STR_REGISTER_OUT ));
  gtk_widget_show (item12);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), item12);

  image68 = gtk_image_new_from_stock ("gtk-no", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image68);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item12), image68);

  item13 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_CHANGE_PASSWD));
  gtk_widget_show (item13);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), item13);

  item14 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_DSP_RSG_INFO));
  gtk_widget_show (item14);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), item14);

  separatormenuitem1 = gtk_menu_item_new ();
  gtk_widget_show (separatormenuitem1);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), separatormenuitem1);
  gtk_widget_set_sensitive (separatormenuitem1, FALSE);

  

  //_______q_1 = gtk_image_menu_item_new_from_stock ("gtk-quit", accel_group);
  _______q_1 = gtk_image_menu_item_new_with_label (STR_TO_UTF8(STR_QUIT));
  gtk_widget_show (_______q_1);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), _______q_1);

  image_______q_1 = gtk_image_new_from_stock ("gtk-quit", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image_______q_1);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (_______q_1), image_______q_1);

  menuitem2 = gtk_menu_item_new_with_mnemonic ( _(STR_TO_UTF8(STR_DSP_PIC))) ;
  gtk_widget_show (menuitem2);
  gtk_container_add (GTK_CONTAINER (menubar1), menuitem2);
  // gtk_widget_set_sensitive(menuitem2, FALSE);   

  menuitem2_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem2), menuitem2_menu);

  item21 = gtk_image_menu_item_new_with_label (STR_TO_UTF8(STR_OPEN_FILE));
  gtk_widget_show (item21);
  gtk_container_add (GTK_CONTAINER (menuitem2_menu), item21);
  gtk_widget_add_accelerator (item21, "activate", accel_group,
                              GDK_o, GDK_CONTROL_MASK,
                              GTK_ACCEL_VISIBLE);

  image69 = gtk_image_new_from_stock ("gtk-open", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image69);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item21), image69);
 

  item22 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_USEFULL_PIC));
  gtk_widget_show (item22);
  gtk_container_add (GTK_CONTAINER (menuitem2_menu), item22);

  item25 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_ZHUJIEXIAN));
  gtk_widget_show (item25);
  gtk_container_add (GTK_CONTAINER (menuitem2_menu), item25);  

  item80 = gtk_menu_item_new_with_mnemonic (STR_TO_UTF8(STR_SELECTLAYER));
  gtk_widget_show (item80);
  gtk_container_add (GTK_CONTAINER (menuitem2_menu), item80);
  
  item80_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (item80), item80_menu);

  item800 = gtk_check_menu_item_new_with_mnemonic (STR_TO_UTF8(STR_USE_LAYER_FILTER));
  gtk_check_menu_item_set_active      (GTK_CHECK_MENU_ITEM(item800),FALSE );
  gtk_widget_show (item800);
  gtk_container_add (GTK_CONTAINER (item80_menu), item800);
  
  item801 = gtk_check_menu_item_new_with_mnemonic (STR_TO_UTF8(STR_LAYER1));
  gtk_check_menu_item_set_active      (GTK_CHECK_MENU_ITEM(item801),TRUE );
  gtk_widget_show (item801);
  gtk_container_add (GTK_CONTAINER (item80_menu), item801);
  
  item802 = gtk_check_menu_item_new_with_mnemonic (STR_TO_UTF8(STR_LAYER2));
  gtk_check_menu_item_set_active      (GTK_CHECK_MENU_ITEM(item802),TRUE );
  gtk_widget_show (item802);
  gtk_container_add (GTK_CONTAINER (item80_menu), item802);
  
  item803 = gtk_check_menu_item_new_with_mnemonic (STR_TO_UTF8(STR_LAYER3));
  gtk_check_menu_item_set_active      (GTK_CHECK_MENU_ITEM(item803),TRUE );
  gtk_widget_show (item803);
  gtk_container_add (GTK_CONTAINER (item80_menu), item803);
  
  item804 = gtk_check_menu_item_new_with_mnemonic (STR_TO_UTF8(STR_LAYER4));
  gtk_check_menu_item_set_active      (GTK_CHECK_MENU_ITEM(item804),TRUE );
  gtk_widget_show (item804);
  gtk_container_add (GTK_CONTAINER (item80_menu), item804);



  item101 = gtk_menu_item_new ();
  gtk_widget_show (item101);
  gtk_container_add (GTK_CONTAINER (menuitem2_menu), item101);
 // gtk_widget_set_sensitive (item101, FALSE);
  
  item26 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_PIC_PRINT));
  gtk_widget_show (item26);
  gtk_container_add (GTK_CONTAINER (menuitem2_menu), item26);

  item24 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_PIC_SOFT_COPY));
  gtk_widget_show (item24);
  gtk_container_add (GTK_CONTAINER (menuitem2_menu), item24);
  
  item27 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_VIEW));  //STR_VIEW 视窗
  gtk_widget_show (item27);
  gtk_container_add (GTK_CONTAINER (menuitem2_menu), item27);

  if(IsHisRdbDisable()!=TRUE)
  {
	  menuitem3 = gtk_menu_item_new_with_mnemonic  (_(STR_TO_UTF8(STR_FAULT_RPLAY)));
	  gtk_widget_show (menuitem3);
	  gtk_container_add (GTK_CONTAINER (menubar1), menuitem3);
	//  gtk_widget_set_sensitive(menuitem3, FALSE);   

	  menuitem3_menu = gtk_menu_new ();
	  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem3), menuitem3_menu);

	  item31 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_FAULT_RPLAY_START));
	  gtk_widget_show (item31);
	  gtk_container_add (GTK_CONTAINER (menuitem3_menu), item31);

	  item32 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_FAULT_RPLAY_STOP));
	  gtk_widget_show (item32);
	  gtk_container_add (GTK_CONTAINER (menuitem3_menu), item32);
 
// 	  _________2 = gtk_menu_item_new ();
// 	  gtk_widget_show (_________2);
// 	  gtk_container_add (GTK_CONTAINER (menuitem3_menu), _________2);
	// gtk_widget_set_sensitive (_________2, FALSE);

 }
  /*item33 = gtk_menu_item_new_with_label (STR_TO_UTF8("UN DEFINE"));
  gtk_widget_show (item33);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), item33);*/

  real_time1 = gtk_menu_item_new_with_mnemonic(_(STR_TO_UTF8(STR_DPS_MOD)));
  gtk_widget_show (real_time1);
  gtk_container_add (GTK_CONTAINER (menubar1), real_time1);
 // gtk_widget_set_sensitive (real_time1, FALSE); 
   group=NULL; 
  real_time1_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (real_time1), real_time1_menu);
  
  /* item41 = gtk_check_menu_item_new_with_label (STR_TO_UTF8(STR_REAL_DSP));*/
  item41 = gtk_radio_menu_item_new_with_label (group,STR_TO_UTF8(STR_REAL_DSP)); 
  gtk_widget_show (item41);
  gtk_container_add (GTK_CONTAINER (real_time1_menu), item41);
  
  group = gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(item41));
  auto_disp_menu = gtk_menu_new ();
  
  for(i=0;i<demo_class_cnt;i++)
  {
        turn[i] = gtk_menu_item_new_with_label (pConvert=_toUtf8(demo_dsp_class[i].class_name));
		G_SAFE_FREE(pConvert);
        gtk_widget_show (turn[i]);
        gtk_container_add (GTK_CONTAINER (auto_disp_menu), turn[i]);
        gtk_signal_connect (GTK_OBJECT (turn[i]), "activate",
                      GTK_SIGNAL_FUNC (on_turn1_activate),
                      GINT_TO_POINTER(i));  
  }
  
  item43 = gtk_radio_menu_item_new_with_label (group ,STR_TO_UTF8(STR_MAN_DSP));
  gtk_widget_show (item43);
  gtk_container_add (GTK_CONTAINER (real_time1_menu), item43);
  group = gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(item43));
  
  item44 = gtk_radio_menu_item_new_with_label (group ,STR_TO_UTF8(STR_DEMO_OFF));
  gtk_widget_show (item44);
  gtk_container_add (GTK_CONTAINER (real_time1_menu), item44);
  
  gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(item44),TRUE);


  item45 = gtk_menu_item_new_with_mnemonic(_(STR_TO_UTF8(OIX_SELECT_TURNDSP_GROUP)));
  gtk_widget_show (item45);
  gtk_container_add (GTK_CONTAINER (real_time1_menu), item45);

  item42 = gtk_menu_item_new_with_mnemonic(_(STR_TO_UTF8(OIX_SELECT_TURNDSP_CONFIG)));
  gtk_widget_show (item42);
  gtk_container_add (GTK_CONTAINER (real_time1_menu), item42);

  item46 = gtk_menu_item_new_with_mnemonic(_(STR_TO_UTF8(OIX_SELECT_TURNSCR_CONFIG)));
  gtk_widget_show (item46);
  gtk_container_add (GTK_CONTAINER (real_time1_menu), item46);

  ______1 = gtk_menu_item_new_with_mnemonic(_(STR_TO_UTF8(STR_ALARM)));
  gtk_widget_show (______1);
  gtk_container_add (GTK_CONTAINER (menubar1), ______1);

  ______1_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (______1), ______1_menu);

  item51 = gtk_image_menu_item_new_with_label (STR_TO_UTF8(STR_ALARM_TAB));
  gtk_widget_show (item51);
  gtk_container_add (GTK_CONTAINER (______1_menu), item51);

  item511 = gtk_image_menu_item_new_with_label (STR_TO_UTF8(STR_KEYSIGNAL_TAB));
  gtk_widget_show (item511);
  gtk_container_add (GTK_CONTAINER (______1_menu), item511);

  image70 = gtk_image_new_from_stock ("gnome-stock-text-bulleted-list", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image70);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item51), image70);

  item52 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_UNRESET_ALARM_TAB));
  gtk_widget_show (item52);
  gtk_container_add (GTK_CONTAINER (______1_menu), item52);

  separatormenuitem1 = gtk_menu_item_new ();
  gtk_widget_show (separatormenuitem1);
  gtk_container_add (GTK_CONTAINER (______1_menu), separatormenuitem1);
  gtk_widget_set_sensitive (separatormenuitem1, FALSE);
  
  
  item53 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_ALARM_ACK));
  gtk_widget_show (item53);
  gtk_container_add (GTK_CONTAINER (______1_menu), item53);


  item54 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_PAGE_ALARM_ACK));
  gtk_widget_show (item54);
  gtk_container_add (GTK_CONTAINER (______1_menu), item54);

  item550 = gtk_menu_item_new_with_label (STR_TO_UTF8(OIX_ALMSTN_DISPLAY_WIN));
  gtk_widget_show (item550);
  GetStationNum(&stn_num);
  if (stn_num>1)//hcl add, atleast 2 station,show this button 
  {
	gtk_container_add (GTK_CONTAINER (______1_menu), item550);
  }

  item55 = gtk_menu_item_new_with_label (STR_TO_UTF8(OIX_ALMINFOR_DISPLAY_WIN));
  gtk_widget_show (item55);
  gtk_container_add (GTK_CONTAINER (______1_menu), item55);

  item56 = gtk_menu_item_new_with_label (STR_TO_UTF8(OIX_SEARCH_EVENT));
 /* gtk_widget_show (item56);  chi  */
  gtk_container_add (GTK_CONTAINER (______1_menu), item56);
/*
 item57 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_OPEN_FILE));
  gtk_widget_show (item57);
  gtk_container_add (GTK_CONTAINER (______1_menu), item57);*/
  
/*******   Database   item ***********/
  
  datamenu = gtk_image_menu_item_new_with_mnemonic (_(STR_TO_UTF8(STR_DATABASE)));
  gtk_widget_show (datamenu);
  gtk_container_add (GTK_CONTAINER (menubar1), datamenu);
  
  data_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (datamenu), data_menu);

  item68 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_DATABASE_TAB));
  gtk_widget_show (item68);
  gtk_container_add (GTK_CONTAINER (data_menu), item68);

  item69 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_SEARCH_PT));
  gtk_widget_show (item69);
  gtk_container_add (GTK_CONTAINER (data_menu), item69);

 item70 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_SEARCH_PROPERTY));
  gtk_widget_show (item70);
  gtk_container_add (GTK_CONTAINER (data_menu), item70);
 
/**************/

  
  
  
  option = gtk_image_menu_item_new_with_mnemonic (_(STR_TO_UTF8(STR_OPTION)));
  gtk_widget_show (option);
  gtk_container_add (GTK_CONTAINER (menubar1), option);
 // gtk_widget_set_sensitive(option, FALSE);  //test

  image71 = gtk_image_new_from_stock ("gtk-preferences", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image71);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (option), image71);

  option_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (option), option_menu);
  
  if(IsHisRdbDisable()!=TRUE)
  {
		item61 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_HIS_CURVE));
		gtk_widget_show (item61);
		gtk_container_add (GTK_CONTAINER (option_menu), item61);
  }
  
//错误日志
  item62 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_PRO_ERR_LOG));
 // gtk_widget_show (item62);
 // gtk_container_add (GTK_CONTAINER (option_menu), item62);

//#ifdef SUN_OS
  item63 = gtk_menu_item_new_with_label (STR_TO_UTF8(OIX_DELETE_HIS_FILE));
  gtk_widget_show (item63);
  gtk_container_add (GTK_CONTAINER (option_menu), item63);
//#endif
  
  item64 = gtk_image_menu_item_new_with_mnemonic (STR_TO_UTF8(STR_CHANGE_BCK_COLOR));
  gtk_widget_show (item64);
  gtk_container_add (GTK_CONTAINER (option_menu), item64);

  
  item65 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_REAL_CURVE));
  gtk_widget_show (item65);
  gtk_container_add (GTK_CONTAINER (option_menu), item65);
  
  item66 = gtk_menu_item_new_with_label (STR_TO_UTF8(OIX_CONFIG_REAL_CRUVE));
  gtk_widget_show (item66);
  gtk_container_add (GTK_CONTAINER (option_menu), item66);

   if (IsCurveWndDisable(OperCharacterCurveDisable) != TRUE)
   {
		itemOperatingCurve= gtk_menu_item_new_with_label (STR_TO_UTF8("STR_OPERATING_CHARACTERISTIC_CURVE"));
		gtk_widget_show (itemOperatingCurve);
		gtk_container_add (GTK_CONTAINER (option_menu), itemOperatingCurve);
   }

  if (IsCurveWndDisable(GenPowerPlanCurveDisable) != TRUE)
  {
		itemGenPowerPlanCurve= gtk_menu_item_new_with_label (STR_TO_UTF8("STR_GEN_POWER_PLAN_CURVE"));
		gtk_widget_show (itemGenPowerPlanCurve);
		gtk_container_add (GTK_CONTAINER (option_menu), itemGenPowerPlanCurve);
  }
  
  item67 = gtk_menu_item_new_with_label (STR_TO_UTF8(OIX_STR_LANG_SET));
#ifdef EXTEND_LANGUAGE_SYSTEM
  gtk_widget_show (item67);
#endif
  gtk_container_add (GTK_CONTAINER (option_menu), item67);

  itemDispEntry  =  gtk_menu_item_new_with_label (STR_TO_UTF8(OIX_STR_PIC_DBPT));
  gtk_widget_show (itemDispEntry);
  gtk_container_add (GTK_CONTAINER (option_menu), itemDispEntry);


  //xun jian
  itemcheck_a = gtk_menu_item_new_with_mnemonic  (STR_TO_UTF8(OIX_STR_AUTO_CHECK));
  gtk_widget_show (itemcheck_a);
  gtk_container_add (GTK_CONTAINER (option_menu), itemcheck_a);

 
  
  itemcheck_a_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (itemcheck_a), itemcheck_a_menu);
  
  
  itemcheck_a01 = gtk_check_menu_item_new_with_mnemonic (STR_TO_UTF8(OIX_STR_AUTO_CHECK));
  //gtk_check_menu_item_set_active      (itemcheck_a01,TRUE );
  gtk_widget_show (itemcheck_a01);
  gtk_container_add (GTK_CONTAINER (itemcheck_a_menu), itemcheck_a01);
 
  opencheck = gtk_menu_item_new_with_mnemonic  (STR_TO_UTF8(OIX_STR_SEARCH_AUTO_CHECK));
  gtk_widget_show (opencheck);
  gtk_container_add (GTK_CONTAINER (itemcheck_a_menu), opencheck);


	itemcheck_b = gtk_menu_item_new_with_mnemonic  (STR_TO_UTF8(OIX_STR_COND_CHECK));
	gtk_widget_show (itemcheck_b);
	gtk_container_add (GTK_CONTAINER (option_menu), itemcheck_b);

//   itemcheck_a02 = gtk_check_menu_item_new_with_mnemonic (_("OIX_STR_CFG_CHECK"));
//   gtk_check_menu_item_set_active      (itemcheck_a02,TRUE );
//   gtk_widget_show (itemcheck_a02);
//   gtk_container_add (GTK_CONTAINER (itemcheck_a_menu), itemcheck_a02);


//#ifdef SUN_OS
  del_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (item63), del_menu);

  sftcp = gtk_menu_item_new_with_label (STR_TO_UTF8(OIX_SOFTCOPY_HIS_FILE));
  gtk_widget_show (sftcp);
  gtk_container_add (GTK_CONTAINER (del_menu), sftcp); 

  sgzy = gtk_menu_item_new_with_label (STR_TO_UTF8(OIX_SGZY_HIS_FILE));
  gtk_widget_show (sgzy);
  gtk_container_add (GTK_CONTAINER (del_menu), sgzy);
//#endif 
  
  
  
  image72 = gtk_image_new_from_stock ("gtk-select-color", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image72);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item64), image72);

  /*_________7 = gtk_menu_item_new ();
  gtk_widget_show (_________7);
  gtk_container_add (GTK_CONTAINER (option_menu), _________7);
  gtk_widget_set_sensitive (_________7, FALSE);

  item65 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_OPEN_FILE));
  gtk_widget_show (item65);
  gtk_container_add (GTK_CONTAINER (option_menu), item65);

  item66 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_OPEN_FILE));
  gtk_widget_show (item66);
  gtk_container_add (GTK_CONTAINER (option_menu), item66);

 item67 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_OPEN_FILE));
  gtk_widget_show (item67);
  gtk_container_add (GTK_CONTAINER (option_menu), item67);*/

  item101 = gtk_image_menu_item_new_with_mnemonic (STR_TO_UTF8(STR_PREV_DSP));
  gtk_widget_show (item101);
  gtk_container_add (GTK_CONTAINER (menubar1), item101);

  image73 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image73);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item101), image73);

  item102 = gtk_image_menu_item_new_with_label (STR_TO_UTF8(STR_NEXT_DSP)); 
  gtk_widget_show (item102);
  gtk_container_add (GTK_CONTAINER (menubar1), item102);

  image74 = gtk_image_new_from_stock ("gtk-go-forward", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image74);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item102), image74);


 
  menuitemRpt = gtk_menu_item_new_with_mnemonic (_(STR_TO_UTF8(STR_RPT)));
//  gtk_widget_set_sensitive (menuitemRpt, FALSE);

#ifdef   WITHREPORT 
  gtk_widget_show (menuitemRpt);
#endif
  gtk_container_add (GTK_CONTAINER (menubar1), menuitemRpt);
  
  menuitemRpt_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitemRpt), menuitemRpt_menu);

   _______rpt_cur_day = gtk_radio_menu_item_new_with_label (rpt_group,STR_TO_UTF8(STR_RPT_CUR_DAY));
  gtk_widget_show (_______rpt_cur_day);
  gtk_container_add (GTK_CONTAINER (menuitemRpt_menu), _______rpt_cur_day);
  rpt_group = gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(_______rpt_cur_day));
  gtk_object_set_data(GTK_OBJECT(main_w[crt_n]),"cur_day_menu",_______rpt_cur_day);
  //g_object_set_data(G_OBJECT(main_w[crt_n]),"cur_day_menu",_______rpt_cur_day);
  
  _______rpt_cur_mon = gtk_radio_menu_item_new_with_label (rpt_group,STR_TO_UTF8(STR_RPT_CUR_MONTH));
  gtk_widget_show (_______rpt_cur_mon);  
  rpt_group = gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(_______rpt_cur_mon));
  gtk_menu_append(GTK_MENU(menuitemRpt_menu),_______rpt_cur_mon);
  gtk_object_set_data(GTK_OBJECT(main_w[crt_n]),"cur_mon_menu",_______rpt_cur_mon);
  
  _______rpt_hist = gtk_radio_menu_item_new_with_label (rpt_group,STR_TO_UTF8(STR_RPT_HIST));
  gtk_widget_show (_______rpt_hist);  
  gtk_menu_append(GTK_MENU(menuitemRpt_menu),_______rpt_hist);
  gtk_object_set_data(GTK_OBJECT(main_w[crt_n]),"hist_rpt_menu",_______rpt_hist);
  
  MenuPointer=getMenuDataPointer(crt_n,CUR_DAY_RPT_DATA);
  gtk_signal_connect (GTK_OBJECT (_______rpt_cur_day), "activate",
                      GTK_SIGNAL_FUNC (Menu_Rpt),
                      (gpointer)MenuPointer);

  MenuPointer=getMenuDataPointer(crt_n,CUR_MONTH_RPT_DATA);
  gtk_signal_connect (GTK_OBJECT (_______rpt_cur_mon), "activate",
                      GTK_SIGNAL_FUNC (Menu_Rpt),
                       (gpointer)(MenuPointer));

  MenuPointer=getMenuDataPointer(crt_n,HIST_RPT_DATA);
  gtk_signal_connect (GTK_OBJECT (_______rpt_hist), "activate",
                      GTK_SIGNAL_FUNC (Menu_Rpt),
                       (gpointer)MenuPointer);
  

  /*************************ots仿真控制菜单 add by dm****************************/
  
  
  menuitem5 = gtk_menu_item_new_with_mnemonic (_(STR_TO_UTF8(STR_SIMU_MENU)));
  gtk_widget_show (menuitem5);
  gtk_container_add (GTK_CONTAINER (menubar1), menuitem5);
  
  menuitem5_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem5), menuitem5_menu);
  
  item_simu_main = gtk_image_menu_item_new_with_label (STR_TO_UTF8(STR_SIMU_MAIN));
  gtk_widget_show (item_simu_main);
  gtk_container_add (GTK_CONTAINER (menuitem5_menu), item_simu_main);
  
  item80 = gtk_image_new_from_file("./images/ots.png");
  gtk_widget_show (item80);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item_simu_main), item80);
  
  item_simu_settask = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_SIMU_SETTASK));
  gtk_widget_show (item_simu_settask);
  gtk_container_add (GTK_CONTAINER (menuitem5_menu), item_simu_settask);
  
  item_simu_setscene = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_SIMU_SETSCENE));
  gtk_widget_show (item_simu_setscene);
  gtk_container_add (GTK_CONTAINER (menuitem5_menu), item_simu_setscene);

  item_simu_setfault = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_SIMU_SETFAULT));
  gtk_widget_show (item_simu_setfault);
  gtk_container_add (GTK_CONTAINER (menuitem5_menu), item_simu_setfault);
  
  item_simu_currenttask = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_SIMU_CURRENTTASK));
  gtk_widget_show (item_simu_currenttask);
  gtk_container_add (GTK_CONTAINER (menuitem5_menu), item_simu_currenttask);
  
  item_simu_revert = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_SIMU_REVERT));
  gtk_widget_show (item_simu_revert);
  gtk_container_add (GTK_CONTAINER (menuitem5_menu), item_simu_revert);
  
  item_simu_local_opr = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_SIMU_LOCAL_OPR));
  gtk_widget_show (item_simu_local_opr);
  gtk_container_add (GTK_CONTAINER (menuitem5_menu), item_simu_local_opr);
  
  item_simu_history = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_SIMU_HISTORY));
  gtk_widget_show (item_simu_history);
  gtk_container_add (GTK_CONTAINER (menuitem5_menu), item_simu_history);
  
  item_simu_sendmsg = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_SIMU_SENDMSG));
  gtk_widget_show (item_simu_sendmsg);
  gtk_container_add (GTK_CONTAINER (menuitem5_menu), item_simu_sendmsg);

  item_simu_exam = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_SIMU_EXAM));
  gtk_widget_show (item_simu_exam);
  gtk_container_add (GTK_CONTAINER (menuitem5_menu), item_simu_exam);

  //   if (hWnd==NULL)
  //   {
  // 	  gtk_widget_set_sensitive(item_clientmain_settask,FALSE);
  // 	  gtk_widget_set_sensitive(item_clientmain_setscene,FALSE);
  // 	  gtk_widget_set_sensitive(item_clientmain_setfault,FALSE);
  // 	  gtk_widget_set_sensitive(item_clientmain_currenttask,FALSE);
  // 	  gtk_widget_set_sensitive(item_clientmain_revert,FALSE);
  // 	  gtk_widget_set_sensitive(item_clientmain_select_opr,FALSE);
  // 	  gtk_widget_set_sensitive(item_clientmain_input_opr,FALSE);
  // 	  gtk_widget_set_sensitive(item_clientmain_history,FALSE);
  //   }
  
/*************************ots窗口切换*****************************************/ 

  menuitem4 = gtk_menu_item_new_with_mnemonic (_(STR_TO_UTF8(STR_HELP)));
  gtk_widget_show (menuitem4);
  gtk_container_add (GTK_CONTAINER (menubar1), menuitem4);

  menuitem4_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem4), menuitem4_menu);

  _______a_1 = gtk_menu_item_new_with_label (STR_TO_UTF8(STR_HELP_ABOUT));
  gtk_widget_show (_______a_1);
  gtk_container_add (GTK_CONTAINER (menuitem4_menu), _______a_1);


#ifdef WINDOWS_OS
  gtk_signal_connect (GTK_OBJECT (item_simu_main), "activate",
						GTK_SIGNAL_FUNC (on_simu_main_activate),
						GINT_TO_POINTER(crt_n));
  
  gtk_signal_connect (GTK_OBJECT (item_simu_settask), "activate",
	  GTK_SIGNAL_FUNC (on_simu_settask_activate),
						GINT_TO_POINTER(crt_n));
  
  gtk_signal_connect (GTK_OBJECT (item_simu_setscene), "activate",
      GTK_SIGNAL_FUNC (on_simu_setscene_activate),
  						GINT_TO_POINTER(crt_n));
  
  gtk_signal_connect (GTK_OBJECT (item_simu_setfault), "activate",
      GTK_SIGNAL_FUNC (on_simu_setfault_activate),
  						GINT_TO_POINTER(crt_n));
  
  gtk_signal_connect (GTK_OBJECT (item_simu_currenttask), "activate",
	  GTK_SIGNAL_FUNC (on_simu_currenttask_activate),
						GINT_TO_POINTER(crt_n));
  
  gtk_signal_connect (GTK_OBJECT (item_simu_revert), "activate",
	  GTK_SIGNAL_FUNC (on_simu_revert_activate),
						GINT_TO_POINTER(crt_n));
  
  gtk_signal_connect (GTK_OBJECT (item_simu_local_opr), "activate",
   	  GTK_SIGNAL_FUNC (on_simu_local_opr_activate),
   						GINT_TO_POINTER(crt_n));
  
  gtk_signal_connect (GTK_OBJECT (item_simu_history), "activate",
	  GTK_SIGNAL_FUNC (on_simu_history_activate),
						GINT_TO_POINTER(crt_n));

  gtk_signal_connect (GTK_OBJECT (item_simu_sendmsg), "activate",
	  GTK_SIGNAL_FUNC (on_simu_sendmsg_activate),
						GINT_TO_POINTER(crt_n));

  gtk_signal_connect (GTK_OBJECT (item_simu_exam), "activate",
	  GTK_SIGNAL_FUNC (on_simu_exam_activate),
						GINT_TO_POINTER(crt_n));
#endif

  gtk_signal_connect (GTK_OBJECT (item11), "activate",
                      GTK_SIGNAL_FUNC (on_reg1_activate),
                      GINT_TO_POINTER(crt_n));
  gtk_signal_connect (GTK_OBJECT (item12), "activate",
                      GTK_SIGNAL_FUNC (on_exit_reg1_activate),
                      GINT_TO_POINTER(crt_n));
  gtk_signal_connect (GTK_OBJECT (item13), "activate",
                      GTK_SIGNAL_FUNC (on_changepwd_activate),
                      GINT_TO_POINTER(crt_n));
  gtk_signal_connect (GTK_OBJECT (item14), "activate",
                      GTK_SIGNAL_FUNC (on_display_reg_info_activate),
                      GINT_TO_POINTER(crt_n));
  gtk_signal_connect (GTK_OBJECT (_______q_1), "activate",
                      GTK_SIGNAL_FUNC (on_quit_activate),
                     GINT_TO_POINTER(crt_n));
  gtk_signal_connect (GTK_OBJECT (item21), "activate",
                      GTK_SIGNAL_FUNC (on_openfile_activate),
                      GINT_TO_POINTER(crt_n));
  gtk_signal_connect (GTK_OBJECT (item22), "activate",
                      GTK_SIGNAL_FUNC (on_CYML_activate),
                      GINT_TO_POINTER(crt_n));

  gtk_signal_connect (GTK_OBJECT (item24), "activate",
                      GTK_SIGNAL_FUNC (on_sftcp_activate),
                      GINT_TO_POINTER(crt_n));
  gtk_signal_connect (GTK_OBJECT (item25), "activate",
                      GTK_SIGNAL_FUNC (on_ZJX_activate),
                      GINT_TO_POINTER(crt_n));

  g_signal_connect ((gpointer) item800, "activate",
	  G_CALLBACK (on_LayerFilter_activate),
	  GINT_TO_POINTER(crt_n));  
//   g_signal_connect ((gpointer) item801, "activate",
// 	  G_CALLBACK (on_Layer1_activate),
// 	  GINT_TO_POINTER(crt_n));
  g_signal_connect ((gpointer) item802, "activate",
	  G_CALLBACK (on_Layer2_activate),
	  GINT_TO_POINTER(crt_n));
  g_signal_connect ((gpointer) item803, "activate",
	  G_CALLBACK (on_Layer3_activate),
	  GINT_TO_POINTER(crt_n));
  g_signal_connect ((gpointer) item804, "activate",
	  G_CALLBACK(on_Layer4_activate),
      GINT_TO_POINTER(crt_n) );

   gtk_signal_connect (GTK_OBJECT (item26), "activate",
                      GTK_SIGNAL_FUNC (on_Hardcpy_activate),
                      GINT_TO_POINTER(crt_n));

   gtk_signal_connect (GTK_OBJECT (item27), "activate",
	   GTK_SIGNAL_FUNC (on_view_activate),
                      GINT_TO_POINTER(crt_n));

//#ifdef SUN_OS
   gtk_signal_connect (GTK_OBJECT (sgzy), "activate",
                      GTK_SIGNAL_FUNC (on_delsgzy_activate),
                      GINT_TO_POINTER(crt_n));
   gtk_signal_connect (GTK_OBJECT (sftcp), "activate",
                      GTK_SIGNAL_FUNC (on_delsftcp_activate),
                      GINT_TO_POINTER(crt_n));  
//#endif

	if(IsHisRdbDisable()!=TRUE)
	{
		gtk_signal_connect (GTK_OBJECT (item31), "activate",
			GTK_SIGNAL_FUNC (Fault_redisplay_activate),
			GINT_TO_POINTER(crt_n));
		gtk_signal_connect (GTK_OBJECT (item32), "activate",
			GTK_SIGNAL_FUNC (End_faultRedisplay_activate),
			GINT_TO_POINTER(crt_n));
	}

  gtk_signal_connect (GTK_OBJECT (item41), "activate",
                      GTK_SIGNAL_FUNC (on_item41_activate),
                      (gpointer)crt_n);
  gtk_signal_connect (GTK_OBJECT (item43), "activate",
                      GTK_SIGNAL_FUNC (on_item43_activate),
                      (gpointer)crt_n);
  gtk_signal_connect (GTK_OBJECT (item44), "activate",
                      GTK_SIGNAL_FUNC (on_item44_activate),
                      (gpointer)crt_n);
  
  gtk_signal_connect (GTK_OBJECT (item45), "activate",
                      GTK_SIGNAL_FUNC (on_item45_activate),
                      (gpointer)crt_n);

  gtk_signal_connect (GTK_OBJECT (item46), "activate",
                      GTK_SIGNAL_FUNC (on_item46_activate),
                      (gpointer)crt_n);
  
  gtk_signal_connect (GTK_OBJECT (item42), "activate",
                      GTK_SIGNAL_FUNC (on_item42_activate),
                      (gpointer)crt_n);

  gtk_signal_connect (GTK_OBJECT (item51), "activate",
                      GTK_SIGNAL_FUNC (on_item51_activate),
                      GINT_TO_POINTER(crt_n));
  gtk_signal_connect (GTK_OBJECT (item52), "activate",
                      GTK_SIGNAL_FUNC (on_UnresetfaultTab_activate),
                      GINT_TO_POINTER(crt_n));
  gtk_signal_connect (GTK_OBJECT (item511), "activate",
	  GTK_SIGNAL_FUNC (on_item511_activate),
                      GINT_TO_POINTER(crt_n));
  
   gtk_signal_connect (GTK_OBJECT (item53), "activate",
                      GTK_SIGNAL_FUNC (on_item53_activate),
                      GINT_TO_POINTER(crt_n));
 
  gtk_signal_connect (GTK_OBJECT (item54), "activate",
                      GTK_SIGNAL_FUNC (on_AckpageAlm_activate),
                      GINT_TO_POINTER(crt_n));
  
  gtk_signal_connect (GTK_OBJECT (item550), "activate",
	  GTK_SIGNAL_FUNC (on_ConfigAlmStn_activate),
                      GINT_TO_POINTER(crt_n));

  gtk_signal_connect (GTK_OBJECT (item55), "activate",
                      GTK_SIGNAL_FUNC (on_ConfigAlmInfo_activate),
                      GINT_TO_POINTER(crt_n));
 
     gtk_signal_connect (GTK_OBJECT (item56), "activate",
                      GTK_SIGNAL_FUNC (on_SearchEvent_activate),
                      GINT_TO_POINTER(crt_n));   
	 if(IsHisRdbDisable()!=TRUE)
        gtk_signal_connect (GTK_OBJECT (item61), "activate",
                      GTK_SIGNAL_FUNC (on_item61_activate),
                      GINT_TO_POINTER(crt_n));
 

    gtk_signal_connect (GTK_OBJECT (item62), "activate",
                        GTK_SIGNAL_FUNC (on_TrabLog_activate),
                        GINT_TO_POINTER(crt_n));
                      
  
  gtk_signal_connect (GTK_OBJECT (item64), "activate",
                      GTK_SIGNAL_FUNC (on_item64_activate),
                      GINT_TO_POINTER(crt_n));
  gtk_signal_connect (GTK_OBJECT (item65), "activate",
                      GTK_SIGNAL_FUNC (on_real_curve_activate),
                      GINT_TO_POINTER(crt_n));
 
  gtk_signal_connect (GTK_OBJECT (item66), "activate",
                      GTK_SIGNAL_FUNC (on_item66_activate),
					GINT_TO_POINTER(crt_n));  

	if (IsCurveWndDisable(OperCharacterCurveDisable) != TRUE)
	{
		g_signal_connect (G_OBJECT (itemOperatingCurve), "activate", 
			G_CALLBACK (on_operating_characteristic_curve_activate), GINT_TO_POINTER(crt_n));
	}

	if (IsCurveWndDisable(GenPowerPlanCurveDisable) != TRUE)
	{
		g_signal_connect (G_OBJECT (itemGenPowerPlanCurve), "activate", 
			G_CALLBACK (on_gen_power_plan_curve_activate), GINT_TO_POINTER(crt_n));
	}

  gtk_signal_connect (GTK_OBJECT (itemDispEntry), "activate",
	  GTK_SIGNAL_FUNC (on_itemDispEntry_activate),
	  GINT_TO_POINTER(crt_n));


  gtk_signal_connect (GTK_OBJECT (itemcheck_a01), "activate",
	  GTK_SIGNAL_FUNC (on_itemcheck_a01_activate),
	  GINT_TO_POINTER(crt_n));

  gtk_signal_connect (GTK_OBJECT (opencheck), "activate",
	  GTK_SIGNAL_FUNC (on_itemcheck_opencheck_activate),
	  GINT_TO_POINTER(crt_n));

  gtk_signal_connect (GTK_OBJECT (itemcheck_b), "activate",
	  GTK_SIGNAL_FUNC (on_itemcheck_b_activate),
	  GINT_TO_POINTER(crt_n)); 


  gtk_signal_connect (GTK_OBJECT (item67), "activate",
	  GTK_SIGNAL_FUNC (on_item67_activate),
	  GINT_TO_POINTER(crt_n));

 gtk_signal_connect (GTK_OBJECT (item68), "activate",
                      GTK_SIGNAL_FUNC (on_Dbtab_activate),
                      GINT_TO_POINTER(crt_n));
 
 gtk_signal_connect (GTK_OBJECT (item69), "activate",
                      GTK_SIGNAL_FUNC (on_SearchPt_activate),
                      GINT_TO_POINTER(crt_n));
 
 gtk_signal_connect (GTK_OBJECT (item70), "activate",
                      GTK_SIGNAL_FUNC (on_SearchWin_activate),
                      GINT_TO_POINTER(crt_n));
 
  gtk_signal_connect (GTK_OBJECT (item101), "button-press-event",
                      GTK_SIGNAL_FUNC (on_previous_activate),
                      GINT_TO_POINTER(crt_n));
  gtk_signal_connect (GTK_OBJECT (item102), "button-press-event",
                      GTK_SIGNAL_FUNC (on_next_activate),
                      GINT_TO_POINTER(crt_n));
  gtk_signal_connect (GTK_OBJECT (_______a_1), "activate",
                      GTK_SIGNAL_FUNC (on________a_1_activate),
                      crt_n);

/*  gtk_signal_connect (GTK_OBJECT (timer_label), "activate",
                      GTK_SIGNAL_FUNC (on_timer_label_activate),
                      crt_n);*/

  

 /* gtk_window_add_accel_group (GTK_WINDOW (window1), accel_group);  */

  return menubar1;
}

