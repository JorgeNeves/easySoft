using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace GameWebSite.Models
{
    public class User_Tag
    {
        [Key]
        private string User_TagID { get; set; }
        private string UserID { get; set; }
        private string TagID { get; set; }
    }
}