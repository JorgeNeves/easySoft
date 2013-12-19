using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace MvcApplication1.Models
{
    public class User_Tag
    {

        public int User_TagID { get; set; }
        public int UserID { get; set; }
        public int TagID { get; set; }
    }
}