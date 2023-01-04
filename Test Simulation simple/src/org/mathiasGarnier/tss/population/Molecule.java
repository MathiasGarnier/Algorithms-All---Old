package org.mathiasGarnier.tss.population;

import org.mathiasGarnier.tss.util.Position2f;

/**
 * Created by Mathias Garnier on 13/12/2016.
 */

public class Molecule extends Position2f {

    /* Can find the entity by his ID. ID of the entity -> (entityID + "." + version)*/
    private String globalName;

    private String entityID;
    private int version;

    /* Start position is (0d;0d) aka origine. */
    private Position2f position2f;

    /* SAMPLE CONSTRUCTOR (Nether used I guessed) */
    @Deprecated
    public Molecule() {

    }

    /* CONSTRUCTOR */
    public Molecule(String _entityID, int _version) {

        this.entityID = _entityID;
        this.version = _version;
    }

    /* GETTERS AND SETTERS */
    public String getGlobalName() {

        return getEntityID().concat(".").concat(String.valueOf(getVersion()));
    }

    public void setGlobalName(String _ID, int _version) {

        this.entityID = _ID;
        this.version = _version;

        this.entityID.concat(".").concat(String.valueOf(this.version));
    }

    public String getEntityID() {

        return entityID;
    }

    public void setEntityID(String _entityID) {

        this.entityID = _entityID;
    }

    public int getVersion() {

        return version;
    }

    public void setVersion(int _version) {

        this.version = _version;
    }
}
