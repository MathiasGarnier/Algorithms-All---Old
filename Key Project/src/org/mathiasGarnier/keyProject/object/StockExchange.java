package org.mathiasGarnier.keyProject.object;

public class StockExchange {

    private int transactionValue;
    
    private Account identifier;

    private Address positionOnMap;
    private Address town;
    
    private Bank tax;
    private Bank accountName;
    
    public StockExchange(int nTransactionValue, Account nIdentifier, Address nPositionOnMap, Address nTown, Bank nTax, Bank nAccountName) {
	
	
    }
    /**
     * @return the transactionValue
     */
    public int getTransactionValue() {
	
	return transactionValue;
    }
    
    /**
     * @param transactionValue the transactionValue to set
     */
    private void setTransactionValue(int transactionValue) {
	
	this.transactionValue = transactionValue;
    }

    /**
     * @return the identifier
     */
    public Account getIdentifier() {
	
	return identifier;
    }

    /**
     * @param identifier the identifier to set
     */
    private void setIdentifier(Account identifier) {
	
	this.identifier = identifier;
    }

    /**
     * @return the positionOnMap
     */
    public Address getPositionOnMap() {
	
	return positionOnMap;
    }

    /**
     * @param positionOnMap the positionOnMap to set
     */
    private void setPositionOnMap(Address positionOnMap) {
	
	this.positionOnMap = positionOnMap;
    }

    /**
     * @return the town
     */
    public Address getTown() {
	
	return town;
    }

    /**
     * @param town the town to set
     */
    private void setTown(Address town) {
	
	this.town = town;
    }

    /**
     * @return the tax
     */
    public Bank getTax() {
	
	return tax;
    }

    /**
     * @param tax the tax to set
     */
    private void setTax(Bank tax) {
	
	this.tax = tax;
    }

    /**
     * @return the accountName
     */
    public Bank getAccountName() {
	
	return accountName;
    }

    /**
     * @param accountName the accountName to set
     */
    private void setAccountName(Bank accountName) {
	
	this.accountName = accountName;
    }
}
