/* Jared Bumgardner
 * COP3055: Project 4
 * StableAsset.java:		Contains implementation of StableAsset type
 */

import java.util.ArrayList;

public class StableAsset extends Asset{
	/* Instance Variables */
	String stableAssetTag;

	/* Accessors & Mutators */
	public String getStableAssetTag() {return this.stableAssetTag;}
	public void setStableAssetTag(String newTag) {this.stableAssetTag = newTag;}
	
	/* Methods */
	@Override
	public String toString() {
		return stableAssetTag + "(" + getName() + ")";
	}

	/* Constructor(s) */
	public StableAsset(ArrayList<Object> description) throws Exception {
		if(description.size() == 3) {	// Correct number of fields provided.
			try {
				this.setName((String) description.get(0));
				this.stableAssetTag = (String) description.get(1);
				this.setExpectedReturn(Double.parseDouble((String) description.get(2)));
				
			} catch(NumberFormatException e) {
				throw new NumberFormatException("Unable to successfully read in data as expected.");
			}
		} else {
			throw new IllegalArgumentException("Unexpected number of arguments detected during Stock obj construction.");
		}
	}
}
