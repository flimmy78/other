package com.bitc.jk.xmis.model.bid;
/**
 * 投标单位
 * @author BomWu
 *
 */
public class BidCompany {
	private String id;
	private String name;
	private int order;
	public int getOrder() {
		return order;
	}
	public void setOrder(int order) {
		this.order = order;
	}
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
}
