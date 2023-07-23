using System;
using System.Data.Entity;
using System.Data.Entity.Validation;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DisplayTable
{
    public partial class DisplayAuthorsTable : Form
    {
        //constructor
        public DisplayAuthorsTable()
        {   
        }

        //Entity Framework DbContext
        private FinalProj.BooksEntities dbcontext = new FinalProj.BooksEntities();

        //load data from database into DataGridView
        private void DisplayTable_Load( object sender, EventArgs e)
        {
            //load authors table ordered by LastName then FirstName
            dbcontext.Authors
                .OrderBy(author => author.LastName)
                .ThenBy(author => author.FirstName)
                .Load();

            //specify DataSource for authorBindingSource
            authorBindingSource.DataSource = dbcontext.Authors.Local;
        }

        //click event handler for the Save Button in the
        //BindingNavigator saves the changes made to the data
        private void authorBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            //validate input fields
            Validate(); //validate the input fields
            authorBindingSource.EndEdit(); ////complete current edit, if any
            // try to save changes
            try
            {
                dbcontext.SaveChanges();
            }
            catch (DbEntityValidationException)
            {
                MessageBox.Show("FirstName and LastName must contain values", "Entity Validation Exception");
            }
        }
    }
}
