using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace GameWebSite.Models
{
    public class Ligacao_Tag
    {
        [Key]
        private string Ligacao_TagID { get; set; }
        private string LigacaoID { get; set; }
        private string TagID { get; set; }
    }
}