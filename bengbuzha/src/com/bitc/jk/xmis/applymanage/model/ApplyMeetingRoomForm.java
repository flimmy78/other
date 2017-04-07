package com.bitc.jk.xmis.applymanage.model;

import java.io.Serializable;
import java.util.Date;

public class ApplyMeetingRoomForm implements Serializable {

	/**
	 * 
	 */
	private static final long serialVersionUID = -6623519264839241847L;

	public String id;
	public String room_id;
	public int priority;
	public int sponsor_id;
	public String reason;
	public Date begin_datetime;
	public Date end_datetime;
	public Date app_datetime;
	public int number_people;
	public int app_user_id;
	public String remark;
	public int assigned_id;
	public Date assigned_datetime;
	public int status_id;


	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getRoom_id() {
		return room_id;
	}

	public void setRoom_id(String room_id) {
		this.room_id = room_id;
	}

	public int getPriority() {
		return priority;
	}

	public void setPriority(int priority) {
		this.priority = priority;
	}

	public int getSponsor_id() {
		return sponsor_id;
	}

	public void setSponsor_id(int sponsor_id) {
		this.sponsor_id = sponsor_id;
	}

	public String getReason() {
		return reason;
	}

	public void setReason(String reason) {
		this.reason = reason;
	}

	public Date getBegin_datetime() {
		return begin_datetime;
	}

	public void setBegin_datetime(Date begin_datetime) {
		this.begin_datetime = begin_datetime;
	}

	public Date getEnd_datetime() {
		return end_datetime;
	}

	public void setEnd_datetime(Date end_datetime) {
		this.end_datetime = end_datetime;
	}

	public Date getApp_datetime() {
		return app_datetime;
	}

	public void setApp_datetime(Date app_datetime) {
		this.app_datetime = app_datetime;
	}

	public int getNumber_people() {
		return number_people;
	}

	public void setNumber_people(int number_people) {
		this.number_people = number_people;
	}

	public int getApp_user_id() {
		return app_user_id;
	}

	public void setApp_user_id(int app_user_id) {
		this.app_user_id = app_user_id;
	}

	public String getRemark() {
		return remark;
	}

	public void setRemark(String remark) {
		this.remark = remark;
	}

	public int getAssigned_id() {
		return assigned_id;
	}

	public void setAssigned_id(int assigned_id) {
		this.assigned_id = assigned_id;
	}

	public Date getAssigned_datetime() {
		return assigned_datetime;
	}

	public void setAssigned_datetime(Date assigned_datetime) {
		this.assigned_datetime = assigned_datetime;
	}

	public int getStatus_id() {
		return status_id;
	}

	public void setStatus_id(int status_id) {
		this.status_id = status_id;
	}

}
